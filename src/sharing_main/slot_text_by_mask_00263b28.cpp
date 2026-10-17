/* HSTMATCH module=hstp_trans_main.prx start=0x00263b28 end=0x00263d94 symbol=FUN_00263b28 lang=c++ */
/* Clone of src/eboot/slot_text_by_mask_002536f0.cpp (hstclone.py tag s10170158a2r1s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Matching idioms: the loop keeps a separate widget counter `k` (retail walks a pointer bumped by 4 with the +16 displacement left in the access); the inlined bit test takes an unused by-value empty Tag, which only reserves the hidden never-written stack slot that makes retail's frame 48 bytes (any single hidden slot gives it); `none()` is `!any()` so the empty test is the materialised `(mask != 0) ^ 1`. */
extern char DAT_002d10cc[];
extern char DAT_002d10d0[];
extern char DAT_002d10d4[];
extern char DAT_003a57e0[];
extern char DAT_002d6fe4[];

struct Hdr { char pad[8]; int count; };
struct Row { const char **strs; int count; int pad; };
struct Bank { int pad0; int loaded; Hdr *hdr; Row *rows; };
struct Widget {
    char pad[0x24];
    int f24;
    int f28;
    char pad2[0xf8 - 0x2c];
    const char *text;
    char pad3[0x138 - 0xfc];
    int dirty;
};
struct Reent { int pad[3]; void *err; };

extern "C" {
Bank *FUN_001991d4(int);
void FUN_00113a50(Widget *);
Reent *FUN_0000fe3c(void);
int FUN_0000f3e8(void *stream, const char *format, ...);
void FUN_0000d530(void);
}

static inline const char *Text(Bank *b, int group, int idx)
{
    if (b->loaded == 0) return DAT_002d10d4;
    if (group < 0 || group >= b->hdr->count) return DAT_002d10d0;
    if (idx < 0 || idx >= b->rows[group].count) return DAT_002d10cc;
    return b->rows[group].strs[idx];
}

struct Tag {};
struct Bits32 {
    unsigned bits;
    bool any() const { return bits != 0; }
    bool none() const { return !any(); }
    unsigned count() const
    {
        unsigned x = bits;
        x = x - ((x >> 1) & 0x55555555);
        x = (x & 0x33333333) + ((x >> 2) & 0x33333333);
        x = (x + (x >> 4)) & 0x0f0f0f0f;
        x = x + (x >> 8);
        return (x + (x >> 16)) & 0xff;
    }
    bool test(unsigned pos, Tag) const
    {
        if (pos >= 32) {
            FUN_0000f3e8(FUN_0000fe3c()->err, DAT_002d6fe4);
            FUN_0000d530();
        }
        return (bits & (1u << pos)) != 0;
    }
};

struct Self {
    Bits32 mask;
    Widget *a;
    Widget *b;
    int base;
    Widget *ws[2];
};

static inline void SetRange(Widget *w, int v)
{
    w->f24 = v;
    w->f28 = v;
}

static inline void SetText(Widget *w, const char *s, int dirty)
{
    w->text = s;
    w->dirty = dirty;
    FUN_00113a50(w);
}

extern "C" void FUN_00263b28(Self *self)
{
    Bank *bank = FUN_001991d4(9);
    int n = bank->rows[1].count;
    if (self->mask.none()) {
        SetRange(self->a, self->base + 1);
        SetRange(self->b, self->base + 1);
        SetText(self->ws[0], DAT_003a57e0, 0);
        SetText(self->ws[1], DAT_003a57e0, 0);
    } else {
        if (self->mask.count() == 1) {
            SetRange(self->a, self->base);
            SetRange(self->b, self->base + 1);
            SetText(self->ws[1], DAT_003a57e0, 0);
        } else {
            SetRange(self->a, self->base);
            SetRange(self->b, self->base);
        }
        int k = 0;
        for (int i = 0; i < n; i++) {
            if (self->mask.test(i, Tag())) {
                const char *s = Text(FUN_001991d4(9), 1, i + 1);
                SetText(self->ws[k], s, 1);
                k++;
            }
        }
    }
}
