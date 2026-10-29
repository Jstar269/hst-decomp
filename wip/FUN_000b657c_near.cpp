/* HSTMATCH module=EBOOT.BIN start=0x000b657c end=0x000b6894 symbol=FUN_000b657c lang=c++ */
/* Hand-written reconstruction from the disassembly; nearest miss 193/198 words, 172 differ, not exact.
   SHAPE ESTABLISHED (matches retail call-for-call): this is a merge of two 80-byte-element ranges
   [f2,l2) and [first,last) into a Helper{cur,c} iterator over a vector of 80-byte Items (Rec + 12 pad).
   The loop compares a by-value copy of *f2 with a by-value copy of *first at +0x38 (Rec.m[14]) and takes
   the smaller; each arm re-checks (cur - c->start)/80 < c->size and either calls Rec assignment
   0xb62e4 or placement-new 0x2f60 + Rec ctor 0xb43e8 then size++. Both tails then walk the remaining range
   through the out-of-line iterator helpers 0xb5d78 (compare), 0xb5ed4 (8-byte copy), 0xb42ac (deref),
   0xb5db8 (construct/assign), 0xb5da4/0xb5d90 (advance +0x50) and 0xb5d60 (write the result iterator).
   RESIDUAL, measured: 193 words vs 198, 172 differ positionally, first at +0x0.
     1. Register colouring is MIRRORED: mwcc colours a0..t0 as s4,s3,s2,s1,s0 here, retail has s0..s4.
        Proved this is not a signature artefact: an isolated 5-pointer + by-value-struct function with the
        same shape (try/lane-work/idiom9.cpp) also colours descending, so retail's ascending order needs the
        original live-set/expression structure, not a different parameter list.
     2. Frame 256 vs retail 304. Retail keeps a SEPARATE 8-byte Helper copy per write arm (sp+288/292 and
        sp+280/284 = 16 bytes) and re-reads pos.c from that copy after each call; ours hoists &pos.c->size into
        s5 (a 6th saved register, hence the extra `sw s5` and the shifted prologue) and elides the copies.
        v5 (write takes Helper by value) and v6 (explicit per-arm Helper copy) both got the copies
        copy-propagated away - mwcc aliases them, retail's did not.
     3. Retail's block-1 source iterator is initialised with `lwc1 f0,52(sp); swc1 f0,276(sp)` - an FP 4-byte
        move, which only a FLOAT source produces (idiom7); a pointer or 4-byte struct copy emits iw/sw
        (idiom6, idiom8). So retail moves that pointer through a float-typed slot; not reproducible from
        natural C++ without a union/punning spelling (not attempted: it would be a matching hack).
   RULED OUT: extra loop-carried local `p2` + `saved` (v1/v2); by-value `Helper` write parameter (v5);
   per-arm `Helper p = pos` before the write (v6); reference write parameter (v4); the v2..v6 family all land
   at 189-193 words and 172-177 differ with the same mirrored colouring.
   NEXT PASS, if wanted: the colouring must be attacked from the live-set side (e.g. a shape in which
   `result` is only live in the tails), and the float-typed slot needs an explanation before block 1 can match.
*/

struct Rec_000b657c {
    float m[16];
    int n;
};

struct Item_000b657c {
    Rec_000b657c rec;
    char pad[12];
};

struct Cont_000b657c {
    int unk0;
    int size;
    Item_000b657c *start;
};

struct Helper_000b657c {
    Item_000b657c *cur;
    Cont_000b657c *c;
};

extern "C" {
void *FUN_000b62e4(void *, const void *);
void *FUN_000b43e8(void *, const void *);
void *FUN_00002f60(unsigned, void *);
int FUN_000b5d78(Item_000b657c *const &, Item_000b657c *const &);
void FUN_000b5ed4(Helper_000b657c &, const Helper_000b657c &);
Item_000b657c *FUN_000b42ac(Item_000b657c *const &);
void *FUN_000b5db8(Helper_000b657c &, const void *);
void FUN_000b5da4(Item_000b657c *&);
void FUN_000b5d90(Item_000b657c *&);
void *FUN_000b5d60(Helper_000b657c &, const Helper_000b657c &);
}

extern "C" void FUN_000b657c(Helper_000b657c *result, Item_000b657c *first, Item_000b657c *last,
                  Item_000b657c *f2, Item_000b657c *l2, Helper_000b657c pos)
{
    Item_000b657c *p2 = f2;

    while (first != last && p2 != l2) {
        Item_000b657c a = *p2;
        Item_000b657c b = *first;
        if (a.rec.m[14] < b.rec.m[14]) {
            if (pos.cur - pos.c->start < pos.c->size) {
                FUN_000b62e4(pos.cur, p2);
            } else {
                void *p = FUN_00002f60(sizeof(Item_000b657c), pos.cur);
                if (p != 0) {
                    FUN_000b43e8(p, p2);
                }
                pos.c->size += 1;
            }
            p2 += 1;
            pos.cur += 1;
        } else {
            if (pos.cur - pos.c->start < pos.c->size) {
                FUN_000b62e4(pos.cur, first);
            } else {
                void *p = FUN_00002f60(sizeof(Item_000b657c), pos.cur);
                if (p != 0) {
                    FUN_000b43e8(p, first);
                }
                pos.c->size += 1;
            }
            first += 1;
            pos.cur += 1;
        }
    }

    if (first == last) {
        Helper_000b657c d = pos;
        Item_000b657c *s = p2;
        Item_000b657c *e = l2;
        while (FUN_000b5d78(s, e)) {
            Helper_000b657c tmp;
            FUN_000b5ed4(tmp, d);
            FUN_000b5db8(tmp, FUN_000b42ac(s));
            FUN_000b5da4(s);
            FUN_000b5d90(d.cur);
        }
        FUN_000b5d60(*result, d);
    } else {
        Helper_000b657c d = pos;
        Item_000b657c *s = first;
        Item_000b657c *e = last;
        while (FUN_000b5d78(s, e)) {
            Helper_000b657c tmp;
            FUN_000b5ed4(tmp, d);
            FUN_000b5db8(tmp, FUN_000b42ac(s));
            FUN_000b5da4(s);
            FUN_000b5d90(d.cur);
        }
        FUN_000b5d60(*result, d);
    }
}
// near miss from lane dsn3 (unreviewed)
