/* HSTMATCH module=hstp_trans_main.prx start=0x001ee644 end=0x001ee7f8 symbol=FUN_001ee644 lang=c99 */
/* Clone of src/eboot/FUN_001e0420.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/result_scene.h"

extern u8 DAT_003b26f0;
extern void FUN_00000a00();
extern u32 * FUN_0001ed28();
extern void FUN_001ef500();
extern int FUN_0022667c(Animator *,int);

/* Deleting destructor of the result scene: destroy all 28 animators, run the base destructor, free when flags > 0. */
ResultScene * FUN_001ee644(ResultScene *self,short flags)
{
  if (self != (ResultScene *)0x0) {
    self->vtable = &DAT_003b26f0;
    FUN_001ef500();
    FUN_0022667c(&self->anim2828,0xffffffff);
    FUN_0022667c(&self->anim279c,0xffffffff);
    FUN_0022667c(&self->anim252c,0xffffffff);
    FUN_0022667c(&self->anim2480,0xffffffff);
    FUN_0022667c(&self->anim22c4,0xffffffff);
    FUN_0022667c(&self->anim2158,0xffffffff);
    FUN_0022667c(&self->anim20cc,0xffffffff);
    FUN_0022667c(&self->anim2040,0xffffffff);
    FUN_0022667c(&self->anim1fb4,0xffffffff);
    FUN_0022667c(&self->anim1f28,0xffffffff);
    FUN_0022667c(&self->anim1cd8,0xffffffff);
    FUN_0022667c(&self->anim1c4c,0xffffffff);
    FUN_0022667c(&self->anim1bc0,0xffffffff);
    FUN_0022667c(&self->anim1b34,0xffffffff);
    FUN_0022667c(&self->anim18c8,0xffffffff);
    FUN_0022667c(&self->anim183c,0xffffffff);
    FUN_0022667c(&self->anim928,0xffffffff);
    FUN_0022667c(&self->anim89c,0xffffffff);
    FUN_0022667c(&self->anim784,0xffffffff);
    FUN_0022667c(&self->anim6f8,0xffffffff);
    FUN_0022667c(&self->anim66c,0xffffffff);
    FUN_0022667c(&self->anim5e0,0xffffffff);
    FUN_0022667c(&self->anim554,0xffffffff);
    FUN_0022667c(&self->anim4c8,0xffffffff);
    FUN_0022667c(&self->anim43c,0xffffffff);
    FUN_0022667c(&self->anim3ac,0xffffffff);
    FUN_0022667c(&self->anim168,0xffffffff);
    FUN_0022667c(&self->anim48,0xffffffff);
    FUN_0001ed28(self,0);
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
