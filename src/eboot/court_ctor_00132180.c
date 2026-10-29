/* HSTMATCH module=EBOOT.BIN start=0x00132180 end=0x00132390 symbol=FUN_00132180 lang=c99 */
/* Hand-written reconstruction from the disassembly; matching idiom: both lists are cleared through local pointers (`l1 = &c->list13fc; l1->data = 0; ...`), and MWCC reuses l1's address computation for the later grow argument `&c->list13fc`, which puts retail's `addiu a0,s0,5116` into the capacity test's beqz delay slot (clearing the members directly computes it at the call and turns the test into beqzl: 46 words off); exact match verified; names and types await human review. */
/* Court.cpp (file name and the g_pCourt name from the assert strings of the debug-build twin): constructor of the court
   object (two polymorphic bases: FUN_0001f06c at +0, FUN_0013fb58 at +0x40, vtables DAT_0030820c / DAT_00308228),
   registers itself as g_pCourt, reserves 16 entries in both lists. Release build of src/sharing_main/court_ctor_0013d738.c
   (same source; the g_pCourt assertion compiles away here). */
#define HST_ASSERT(cond) do { } while (0)
#define LIST_RESERVE 16 /* entries reserved in both lists */

#include "hst/court.h"

extern char DAT_0030820c[];
extern char DAT_00308228[];
extern unsigned char DAT_003386b8;
extern Court *DAT_003402a0;     /* g_pCourt */
extern int DAT_003417c4;
extern unsigned char DAT_003417cc;
extern void FUN_0001f06c(Court *);
extern void FUN_0013fb58(void *);
extern void FUN_000c4040(RawVec *, unsigned int);
extern void FUN_0012ca4c(RawVec *, unsigned int);
extern int FUN_002b78f8(void);
extern void FUN_000133f4(int);
extern int FUN_0001342c(void);
extern void FUN_0013293c(Court *, int);

/* Court constructor: build both bases, clear the state, register as the global court, reserve the lists and pick the mode. */
Court *FUN_00132180(Court *c)
{
    unsigned int m;
    RawVec *l1;
    RawVec *l2;

    FUN_0001f06c(c);
    FUN_0013fb58(&c->vptr1);
    c->vptr = DAT_0030820c;
    c->vptr1 = DAT_00308228;
    c->unk1360 = 1;
    c->mode = 1;
    c->unk1368 = 0;
    c->unk136c = 0;
    c->unk1370[0] = -1;
    c->unk1370[1] = -1;
    c->unk1370[2] = -1;
    c->unk1370[3] = -1;
    c->unk1370[4] = -1;
    c->unk1384[0] = 0;
    c->unk1384[1] = 0;
    c->vec138c.data = 0;
    c->vec138c.size = 0;
    c->vec138c.capacity = 0;
    c->vec1398.data = 0;
    c->vec1398.size = 0;
    c->vec1398.capacity = 0;
    c->vec13a4.data = 0;
    c->vec13a4.size = 0;
    c->vec13a4.capacity = 0;
    c->vec13b0.data = 0;
    c->vec13b0.size = 0;
    c->vec13b0.capacity = 0;
    c->vec13bc.data = 0;
    c->vec13bc.size = 0;
    c->vec13bc.capacity = 0;
    c->vec13cc.data = 0;
    c->vec13cc.size = 0;
    c->vec13cc.capacity = 0;
    c->vec13d8.data = 0;
    c->vec13d8.size = 0;
    c->vec13d8.capacity = 0;
    c->vec13e4.data = 0;
    c->vec13e4.size = 0;
    c->vec13e4.capacity = 0;
    c->vec13f0.data = 0;
    c->vec13f0.size = 0;
    c->vec13f0.capacity = 0;
    l1 = &c->list13fc;
    l1->data = 0;
    l1->size = 0;
    l1->capacity = 0;
    c->vec1408.data = 0;
    c->vec1408.size = 0;
    c->vec1408.capacity = 0;
    c->unk1414 = 1;
    c->unk1415 = 1;
    c->unk1418 = 0;
    c->unk141c = 0;
    c->unk141d = 1;
    c->unk141e = 0;
    c->unk141f = 1;
    c->unk142c = 0;
    l2 = &c->list1430;
    l2->data = 0;
    l2->size = 0;
    l2->capacity = 0;
    c->unk143c = 0;
    c->unk1440 = 1;
    c->unk1444 = 0;
    c->unk1448 = -1;
    c->unk144c = -1;
    c->vec1450.data = 0;
    c->vec1450.size = 0;
    c->vec1450.capacity = 0;
    c->unk145c = -1;
    c->unk14b0 = 0;
    c->unk14b1 = 0;
    c->unk14b2 = 0;
    c->unk14b4 = 0;
    HST_ASSERT(DAT_003402a0 == 0);
    DAT_003402a0 = c;
    if (c->list13fc.capacity < LIST_RESERVE) {
        FUN_000c4040(&c->list13fc, LIST_RESERVE);
    }
    if (c->list1430.capacity < LIST_RESERVE) {
        FUN_0012ca4c(&c->list1430, LIST_RESERVE);
    }
    if (DAT_003386b8 != 0) {
        c->unk1360 = DAT_003417c4;
    } else {
        FUN_000133f4(FUN_002b78f8());
        c->unk1360 = FUN_0001342c();
    }
    m = DAT_003417cc;
    c->mode = m;
    if (m == 0 || m - 10 < 3) {
        c->mode = 1;
    }
    FUN_0013293c(c, c->mode);
    c->unk13c8 = 0;
    return c;
}
