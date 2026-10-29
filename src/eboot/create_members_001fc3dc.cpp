/* HSTMATCH module=EBOOT.BIN start=0x001fc3dc end=0x001fc4e8 symbol=FUN_001fc3dc lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1/v0c) corrected by hand: typed members and ctor results, `p = operator new(n); if (p) p = ctor(p);` allocation pattern, lui/addiu module addresses passed as symbol addresses; readability pass; exact match verified; names and types await human review. */
#include "hst/part_holder.h"

extern char DAT_002ef01c[];
extern char DAT_002ef028[];
extern char DAT_0030ebf4[];
extern PartD *DAT_003403f8;  /* shared instance of part D, reused when it exists */
extern "C" void FUN_00000020(void *);
extern "C" void FUN_00000028();
extern "C" void FUN_0001cad0(void *, int, void *);
extern "C" void FUN_0001cb88(void *);
extern "C" PartA *FUN_001fba78(PartA *);
extern "C" PartB *FUN_001fbfa8(PartB *);
extern "C" PartC *FUN_001fbbd0(PartC *);
extern "C" PartD *FUN_00159f08(PartD *, int);
extern "C" void FUN_00103628(PartA *, int);

/* Create the parts: A always, B, C and D unless minimal is set. */
extern "C" void FUN_001fc3dc(PartHolder *self, int minimal) {
    FUN_00000020(DAT_002ef01c);
    FUN_0001cad0(DAT_0030ebf4, 1, DAT_002ef028);
    PartA *a = (PartA *)operator new(sizeof(PartA));
    if (a) a = FUN_001fba78(a);
    self->partA = a;
    FUN_00103628(a, 1);
    if (minimal == 0) {
        PartB *b = (PartB *)operator new(sizeof(PartB));
        if (b) b = FUN_001fbfa8(b);
        self->partB = b;
        PartC *c = (PartC *)operator new(sizeof(PartC));
        if (c) c = FUN_001fbbd0(c);
        self->partC = c;
    }
    FUN_0001cb88(DAT_0030ebf4);
    if (minimal == 0) {
        if (DAT_003403f8) {
            self->partD = DAT_003403f8;
        } else {
            PartD *d = (PartD *)operator new(sizeof(PartD));
            if (d) d = FUN_00159f08(d, 0);
            self->partD = d;
        }
    }
    FUN_00000028();
}
