/* HSTMATCH module=EBOOT.BIN start=0x000b657c end=0x000b6894 symbol=FUN_000b657c lang=c++ */
/* std::merge(first, last, f2, l2, out, comp) for an 80-byte record element whose sort key is
   .rec.m[14], writing through an output iterator Helper{cur, c} whose assign-or-construct body is
   the already-matched FUN_000b5db8. Comparator is the naive by-value form - that is what produces
   retail's two 80-byte parameter copies and the float-typed spill slot (lwc1/swc1).
   Hand-written from the disassembly; not exact. */
#include <stddef.h>

struct Rec {
    float m[16];
    int n;
};

struct Item {
    Rec rec;
    char pad[12];
};

struct Cont {
    int unk0;
    int size;
    Item *start;
};

struct Helper {
    Item *cur;
    Cont *c;
};

struct Less {
    bool operator()(Item a, Item b) const { return a.rec.m[14] < b.rec.m[14]; }
};

extern "C" {
void FUN_000b62e4(void *, const void *);
void FUN_000b43e8(void *, const void *);
void *FUN_00002f60(unsigned, void *);
int FUN_000b5d78(Item *const &, Item *const &);
void FUN_000b5ed4(Helper &, const Helper &);
Item *FUN_000b42ac(Item *const &);
void *FUN_000b5db8(Helper &, const void *);
void FUN_000b5da4(Item *&);
void FUN_000b5d90(Item *&);
void *FUN_000b5d60(Helper &, const Helper &);
}

extern "C" void FUN_000b657c(Helper *result, Item *first, Item *last,
                             Item *f2, Item *l2, Helper pos)
{
    Less comp;

    while (first != last && f2 != l2) {
        Helper out = pos;
        if (comp(*f2, *first)) {
            FUN_000b5db8(out, f2);
            FUN_000b5da4(out.cur);
            ++f2;
        } else {
            FUN_000b5db8(out, first);
            FUN_000b5d90(out.cur);
            ++first;
        }
        pos = out;
    }

    if (first == last) {
        Helper d = pos;
        Item *s = f2;
        Item *e = l2;
        while (FUN_000b5d78(s, e)) {
            Helper tmp;
            FUN_000b5ed4(tmp, d);
            FUN_000b5db8(tmp, FUN_000b42ac(s));
            FUN_000b5da4(s);
            FUN_000b5d90(d.cur);
        }
        FUN_000b5d60(*result, d);
    } else {
        Helper d = pos;
        Item *s = first;
        Item *e = last;
        while (FUN_000b5d78(s, e)) {
            Helper tmp;
            FUN_000b5ed4(tmp, d);
            FUN_000b5db8(tmp, FUN_000b42ac(s));
            FUN_000b5da4(s);
            FUN_000b5d90(d.cur);
        }
        FUN_000b5d60(*result, d);
    }
}

/* IDENTITY CORRECTION (pass 51): this function is NOT an insert-fill. It is std::merge over an
   80-byte record with the key at .rec.m[14], writing through the output iterator Helper{cur,c}
   whose assign-or-construct member is the already-matched FUN_000b5db8, with a naive BY-VALUE
   comparator (that is the source of retail's two 80-byte parameter copies and its float spill
   slot, and of the per-arm Helper temporaries).
   MEASURED: 141/196 words, 187 differ, frame 256 vs 304, saved regs ra,s0..s4 EXACTLY matching
   retail's. The by-value comparator therefore explains the frame/colour but this draft is 55 words
   SHORT: retail's merge loop carries more per-arm work than the four calls written here.
   Kept alongside wip/FUN_000b657c_near.cpp (193/198, 172 differ), which is still the better draft
   by differing words but was built on the wrong identity. Next: enumerate the per-arm calls in
   b657c.dis (the two write arms have their own Helper copy at 288/292 and 280/284) and re-shape
   this file, not the old one. */
// near miss from lane dsn3 (unreviewed)
