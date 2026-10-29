/* HSTMATCH module=EBOOT.BIN start=0x001ce13c end=0x001ce280 symbol=FUN_001ce13c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
struct Vec4 {
    float x, y, z, w;
} __attribute__((aligned(16)));

#include "hst/range_obj.h"

struct Item {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int v6();
};

extern "C" {
int FUN_001cde28(Item *p);
int FUN_001ce328(Item *p);
int FUN_001ce320(Item *p);
int FUN_001ce318(int x);
int FUN_001ce280(RangeObj *self, Item *p);
int FUN_001cdcb0(Item *p);
int FUN_0028bd5c(int a, Item *p);
void FUN_000542e8(Vec4 *out, int a, void *b);
void FUN_000c3f38(Vec4 *out, Vec4 *in);
int FUN_001cdca8(Item *p);
int FUN_001cdc9c(int x);
float FUN_001cdda8(int a, Vec4 *v);
}

/* Test the referenced item (null and the first predicates, then a range test, and for one kind a position test and a facing test) and return the negated result. */
extern "C" unsigned char FUN_001ce13c(RangeObj *self, Item **item_ref)
{
    Item *p = *item_ref;
    bool r = false;
    if (p != 0) {
        if (FUN_001cde28(p) != 0) {
            if (FUN_001ce328(p) != 0) {
                r = !FUN_001ce318(FUN_001ce320(p)) && FUN_001ce280(self, p) != 0;
            } else if (FUN_001cdcb0(p) != 0) {
                r = FUN_001ce280(self, p) != 0 && FUN_0028bd5c(self->unk40, p) != 0;
                if (r) {
                    Vec4 b;
                    Vec4 a;
                    FUN_000542e8(&a, p->v6(), self->pos);
                    FUN_000c3f38(&b, &a);
                    float value = FUN_001cdda8(FUN_001cdc9c(FUN_001cdca8(p)) + 0x20, &b);
                    if (value >= 0.0f)
                        r = false;
                    else
                        r = true;
                }
            }
        }
    }
    return !r;
}
