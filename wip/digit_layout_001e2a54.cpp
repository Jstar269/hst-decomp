/* HSTMATCH module=EBOOT.BIN start=0x001e2a54 end=0x001e2c84 symbol=FUN_001e2a54 lang=c++ */
/* Hand-written reconstruction from the disassembly; NOT exact: same opcodes as retail (140 words), 22 words differ in register naming/load order of the post-loop block only; names and types await human review. */
struct Widget {
    char pad0[4];
    short x;
    short pad6;
    short x2;
    char padA[4];
    unsigned short flags;
    char pad10[0x24 - 0x10];
    int v24;
    int v28;
};
struct Slot {
    Widget *w;
    int pad[4];
};
struct Self {
    char pad[0xdc];
    Slot items[5];
    int left;
    int right;
    char pad3[0x164 - 0x148];
    int total;
};

extern "C" void *FUN_001ee200();
extern "C" int FUN_001fb524(void *);
extern "C" void FUN_000ffb3c(Widget *, int);

static inline void MoveX(Widget *w, short x)
{
    short d = x - w->x;
    w->x = x;
    w->x2 = w->x2 + d;
}

extern "C" void FUN_001e2a54(Self *self)
{
    int num = FUN_001fb524(FUN_001ee200());
    int div = 100;
    int lead = -1;
    for (int i = 0; i < 3; i++) {
        Slot *s = &self->items[i + 1];
        int q = num / div;
        if (q == 0 && i < 2 && lead < 0) {
            FUN_000ffb3c(s->w, 1);
        } else {
            if (lead < 0) {
                lead = 3 - i;
            }
            FUN_000ffb3c(s->w, 0);
            s->w->v24 = s->w->v28 + q;
        }
        num = num % div;
        div = div / 10;
    }
    Slot *last = &self->items[4];
    int left = self->left;
    int span = self->total - left;
    int gap = self->right - left;
    Widget *base = self->items[0].w;
    Slot *p = &self->items[1];
    int w0 = (short)(p->w->x2 - p->w->x);
    int w3 = (short)(last->w->x2 - last->w->x);
    int rem = span - w0 * (3 - lead);
    int half = rem / 2;
    int start = 0xf0 - half;
    int end = half + 0xf0;
    MoveX(base, start);
    int pos = start + gap;
    int i = 0;
    int acc = 0;
    for (; i < 3; i++) {
        Widget *w = p->w;
        if ((w->flags & 3) == 0) {
            MoveX(w, pos + acc);
            acc = acc + w0;
        }
        p++;
    }
    MoveX(last->w, end - w3);
}
// Near miss, snE1-00: part 1 (digit loop) is exact; part 2 differs by registers only (retail loads left/total/right/base first into a1/a0/v1/a2, subtracts, then loads the two widget pointers; ours interleaves).
// Ruled out: statement order of the local declarations (1260 permutations, best 32 words), Width(const) getter, rem>>1 form (rem / 2 is right: gives the duplicated delay-slot sra), explicit pos/end locals (both needed for the opcode match).
// Lane wf20261026-e01-05: 32 -> 22. `span = total - left` and `gap = right - left` as their own locals (retail computes both
// subtractions early, a3 = gap feeds pos), and `int i = 0; int acc = 0; for (; i < 3; i++)` (retail zeroes i (t1) before acc (a3)):
// the second loop is now exact. Remaining 22 words: the 0x1e2b40 prelude schedule (retail issues left/total/right/base loads and both
// subtractions before the widget-pointer loads; ours starts with p->w). All 120 orders of span/gap/base/w0/w3 give 22 (try/lane-work/1e2a54/p).
// improved by lane wf20261026-e01-05 (unreviewed): 32 -> 22 differing words
