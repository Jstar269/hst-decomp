/* HSTMATCH module=hstp_trans_main.prx start=0x0014be3c end=0x0014c118 symbol=FUN_0014be3c lang=c99 */
/* Clone of src/eboot/FUN_001407f0.c (hstclone.py tag c28): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/xform_host.h"

extern u8 DAT_003b1510;
extern void FUN_00000788();
extern void FUN_00000a00();
extern int * FUN_00049200();
extern int * FUN_00060478();
extern int * FUN_000ed9b8();
extern void FUN_0014c3a4();
extern int * FUN_00151fc4();
extern int * FUN_00152070();
extern int * FUN_001521cc();
extern int * FUN_00152278();
extern int * FUN_001523c4();
extern int * FUN_001525c8();
extern int * FUN_00152a70();
extern int * FUN_00152bb0();
extern int * FUN_00152c6c();
extern int * FUN_00152db8();
extern int * FUN_00152e64();
extern void FUN_0013d980();
extern void FUN_0014bdbc();

/* Destroys the sub-objects in reverse order; deletes the object itself when flag > 0. */
XformHost * FUN_0014be3c(XformHost *self, short flag)
{
  void *sub;

  if (self != 0) {
    self->vtable = &DAT_003b1510;
    FUN_0014c3a4();
    sub = (void *)&self->entries;
    if (sub != 0 && sub != 0) {
      FUN_00152e64(sub, 0);
    }
    sub = (void *)&self->subc04;
    if (sub != 0 && sub != 0) {
      FUN_00152db8(sub, 0);
    }
    sub = (void *)&self->subaf8;
    if (sub != 0 && sub != 0) {
      FUN_00152db8(sub, 0);
    }
    sub = (void *)&self->sub9ec;
    if (sub != 0 && sub != 0) {
      FUN_00152db8(sub, 0);
    }
    sub = (void *)&self->sub8e0;
    if (sub != 0 && sub != 0) {
      FUN_00152c6c(sub, 0);
    }
    sub = (void *)&self->sub8d4;
    if (sub != 0 && sub != 0) {
      FUN_00152bb0(sub, 0);
    }
    sub = (void *)&self->sub8c8;
    if (sub != 0 && sub != 0) {
      FUN_00152a70(sub, 0);
    }
    sub = (void *)&self->sub7bc;
    if (sub != 0 && sub != 0) {
      FUN_001525c8(sub, 0);
    }
    sub = (void *)&self->sub7b0;
    if (sub != 0 && sub != 0) {
      FUN_000ed9b8(sub, 0);
    }
    sub = (void *)&self->sub7a4;
    if (sub != 0 && sub != 0) {
      FUN_001523c4(sub, 0);
    }
    FUN_00049200(self->sub160, 0xffffffff);
    sub = (void *)&self->sub154;
    if (sub != 0 && sub != 0) {
      FUN_00152278(sub, 0);
    }
    sub = (void *)&self->sub148;
    if (sub != 0 && sub != 0) {
      FUN_001521cc(sub, 0);
    }
    sub = (void *)&self->sub13c;
    if (sub != 0 && sub != 0) {
      FUN_001521cc(sub, 0);
    }
    sub = (void *)&self->sub130;
    if (sub != 0 && sub != 0) {
      FUN_001521cc(sub, 0);
    }
    sub = (void *)&self->sub124;
    if (sub != 0 && sub != 0) {
      FUN_001521cc(sub, 0);
    }
    sub = (void *)&self->sub118;
    if (sub != 0 && sub != 0) {
      FUN_001521cc(sub, 0);
    }
    FUN_00000788(self->arrd0, FUN_0013d980, 0xc, 6);
    FUN_00000788(self->arr88, FUN_0014bdbc, 0xc, 6);
    FUN_00000788(self->arr40, FUN_0013d980, 0xc, 6);
    sub = (void *)&self->sub34;
    if (sub != 0 && sub != 0) {
      FUN_00060478(sub, 0);
    }
    sub = (void *)&self->sub28;
    if (sub != 0 && sub != 0) {
      FUN_00152070(sub, 0);
    }
    sub = (void *)&self->sub1c;
    if (sub != 0 && sub != 0) {
      FUN_00151fc4(sub, 0);
    }
    sub = (void *)&self->sub10;
    if (sub != 0 && sub != 0) {
      FUN_00151fc4(sub, 0);
    }
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
