/* HSTMATCH module=hstp_trans_main.prx start=0x0013da04 end=0x0013dbf0 symbol=FUN_0013da04 lang=c99 */
/* Clone of src/eboot/FUN_001323e8.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/court.h"

extern u8 DAT_003b14d8;
extern u8 DAT_003b14f4;
extern Court *DAT_003e95e0;
extern void FUN_00000a00();
extern u32 * FUN_0001ed28();
extern int * FUN_000550a0();
extern int * FUN_0006026c();
extern int * FUN_000ed9b8();
extern void FUN_0013dbf0();
extern int * FUN_00147f54();
extern int * FUN_00148068();
extern int * FUN_00148114();
extern int * FUN_001481c0();
extern int * FUN_0014826c();
extern int * FUN_00148318();
extern int * FUN_001483d4();
extern int * FUN_00148490();
extern int * FUN_0014854c();
extern int * FUN_001485f8();
extern u32 * FUN_0014be3c();

/* Court destructor: reset the vtables, unregister, destroy the member arrays in reverse order, then both bases. */
Court * FUN_0013da04(Court *self,short flag)
{
  RawVec *member;
  
  if (self != (Court *)0x0) {
    self->vptr = &DAT_003b14d8;
    self->vptr1 = &DAT_003b14f4;
    FUN_0013dbf0();
    member = &self->vec1450;
    DAT_003e95e0 = 0;
    if ((member != (RawVec *)0x0) && (member != (RawVec *)0x0)) {
      FUN_001485f8(member,0);
    }
    member = &self->list1430;
    if ((member != (RawVec *)0x0) && (member != (RawVec *)0x0)) {
      FUN_000ed9b8(member,0);
    }
    member = &self->vec1408;
    if ((member != (RawVec *)0x0) && (member != (RawVec *)0x0)) {
      FUN_0006026c(member,0);
    }
    member = &self->list13fc;
    if ((member != (RawVec *)0x0) && (member != (RawVec *)0x0)) {
      FUN_000550a0(member,0);
    }
    member = &self->vec13f0;
    if ((member != (RawVec *)0x0) && (member != (RawVec *)0x0)) {
      FUN_00147f54(member,0);
    }
    member = &self->vec13e4;
    if ((member != (RawVec *)0x0) && (member != (RawVec *)0x0)) {
      FUN_0014854c(member,0);
    }
    member = &self->vec13d8;
    if ((member != (RawVec *)0x0) && (member != (RawVec *)0x0)) {
      FUN_00148490(member,0);
    }
    member = &self->vec13cc;
    if ((member != (RawVec *)0x0) && (member != (RawVec *)0x0)) {
      FUN_001483d4(member,0);
    }
    member = &self->vec13bc;
    if ((member != (RawVec *)0x0) && (member != (RawVec *)0x0)) {
      FUN_00148318(member,0);
    }
    member = &self->vec13b0;
    if ((member != (RawVec *)0x0) && (member != (RawVec *)0x0)) {
      FUN_0014826c(member,0);
    }
    member = &self->vec13a4;
    if ((member != (RawVec *)0x0) && (member != (RawVec *)0x0)) {
      FUN_001481c0(member,0);
    }
    member = &self->vec1398;
    if ((member != (RawVec *)0x0) && (member != (RawVec *)0x0)) {
      FUN_00148114(member,0);
    }
    member = &self->vec138c;
    if ((member != (RawVec *)0x0) && (member != (RawVec *)0x0)) {
      FUN_00148068(member,0);
    }
    FUN_0014be3c(&self->vptr1,0);
    FUN_0001ed28(self,0);
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
