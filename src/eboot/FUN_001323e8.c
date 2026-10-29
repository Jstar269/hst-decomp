/* HSTMATCH module=EBOOT.BIN start=0x001323e8 end=0x001325d4 symbol=FUN_001323e8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s512a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/court.h"

extern u8 DAT_0030820c;
extern u8 DAT_00308228;
extern Court *DAT_003402a0;
extern void FUN_00000a00();
extern u32 * FUN_0001f0f0();
extern int * FUN_00054554();
extern int * FUN_0005f47c();
extern int * FUN_000e88e4();
extern void FUN_001325d4();
extern int * FUN_0013c908();
extern int * FUN_0013ca1c();
extern int * FUN_0013cac8();
extern int * FUN_0013cb74();
extern int * FUN_0013cc20();
extern int * FUN_0013cccc();
extern int * FUN_0013cd88();
extern int * FUN_0013ce44();
extern int * FUN_0013cf00();
extern int * FUN_0013cfac();
extern u32 * FUN_001407f0();

/* Court destructor: reset the vtables, unregister, destroy the member arrays in reverse order, then both bases. */
Court * FUN_001323e8(Court *self,short flag)
{
  RawVec *member;
  
  if (self != (Court *)0x0) {
    self->vptr = &DAT_0030820c;
    self->vptr1 = &DAT_00308228;
    FUN_001325d4();
    member = &self->vec1450;
    DAT_003402a0 = 0;
    if ((member != (RawVec *)0x0) && (member != (RawVec *)0x0)) {
      FUN_0013cfac(member,0);
    }
    member = &self->list1430;
    if ((member != (RawVec *)0x0) && (member != (RawVec *)0x0)) {
      FUN_000e88e4(member,0);
    }
    member = &self->vec1408;
    if ((member != (RawVec *)0x0) && (member != (RawVec *)0x0)) {
      FUN_0005f47c(member,0);
    }
    member = &self->list13fc;
    if ((member != (RawVec *)0x0) && (member != (RawVec *)0x0)) {
      FUN_00054554(member,0);
    }
    member = &self->vec13f0;
    if ((member != (RawVec *)0x0) && (member != (RawVec *)0x0)) {
      FUN_0013c908(member,0);
    }
    member = &self->vec13e4;
    if ((member != (RawVec *)0x0) && (member != (RawVec *)0x0)) {
      FUN_0013cf00(member,0);
    }
    member = &self->vec13d8;
    if ((member != (RawVec *)0x0) && (member != (RawVec *)0x0)) {
      FUN_0013ce44(member,0);
    }
    member = &self->vec13cc;
    if ((member != (RawVec *)0x0) && (member != (RawVec *)0x0)) {
      FUN_0013cd88(member,0);
    }
    member = &self->vec13bc;
    if ((member != (RawVec *)0x0) && (member != (RawVec *)0x0)) {
      FUN_0013cccc(member,0);
    }
    member = &self->vec13b0;
    if ((member != (RawVec *)0x0) && (member != (RawVec *)0x0)) {
      FUN_0013cc20(member,0);
    }
    member = &self->vec13a4;
    if ((member != (RawVec *)0x0) && (member != (RawVec *)0x0)) {
      FUN_0013cb74(member,0);
    }
    member = &self->vec1398;
    if ((member != (RawVec *)0x0) && (member != (RawVec *)0x0)) {
      FUN_0013cac8(member,0);
    }
    member = &self->vec138c;
    if ((member != (RawVec *)0x0) && (member != (RawVec *)0x0)) {
      FUN_0013ca1c(member,0);
    }
    FUN_001407f0(&self->vptr1,0);
    FUN_0001f0f0(self,0);
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
