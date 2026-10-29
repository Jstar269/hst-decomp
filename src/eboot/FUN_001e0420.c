/* HSTMATCH module=EBOOT.BIN start=0x001e0420 end=0x001e05d4 symbol=FUN_001e0420 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s512a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/result_scene.h"

extern u8 DAT_00309424;
extern void FUN_00000a00();
extern u32 * FUN_0001f0f0();
extern void FUN_001e12dc();
extern int FUN_002175d4(Animator *,int);

/* Deleting destructor of the result scene: destroy all 28 animators, run the base destructor, free when flags > 0. */
ResultScene * FUN_001e0420(ResultScene *self,short flags)
{
  if (self != (ResultScene *)0x0) {
    self->vtable = &DAT_00309424;
    FUN_001e12dc();
    FUN_002175d4(&self->anim2828,0xffffffff);
    FUN_002175d4(&self->anim279c,0xffffffff);
    FUN_002175d4(&self->anim252c,0xffffffff);
    FUN_002175d4(&self->anim2480,0xffffffff);
    FUN_002175d4(&self->anim22c4,0xffffffff);
    FUN_002175d4(&self->anim2158,0xffffffff);
    FUN_002175d4(&self->anim20cc,0xffffffff);
    FUN_002175d4(&self->anim2040,0xffffffff);
    FUN_002175d4(&self->anim1fb4,0xffffffff);
    FUN_002175d4(&self->anim1f28,0xffffffff);
    FUN_002175d4(&self->anim1cd8,0xffffffff);
    FUN_002175d4(&self->anim1c4c,0xffffffff);
    FUN_002175d4(&self->anim1bc0,0xffffffff);
    FUN_002175d4(&self->anim1b34,0xffffffff);
    FUN_002175d4(&self->anim18c8,0xffffffff);
    FUN_002175d4(&self->anim183c,0xffffffff);
    FUN_002175d4(&self->anim928,0xffffffff);
    FUN_002175d4(&self->anim89c,0xffffffff);
    FUN_002175d4(&self->anim784,0xffffffff);
    FUN_002175d4(&self->anim6f8,0xffffffff);
    FUN_002175d4(&self->anim66c,0xffffffff);
    FUN_002175d4(&self->anim5e0,0xffffffff);
    FUN_002175d4(&self->anim554,0xffffffff);
    FUN_002175d4(&self->anim4c8,0xffffffff);
    FUN_002175d4(&self->anim43c,0xffffffff);
    FUN_002175d4(&self->anim3ac,0xffffffff);
    FUN_002175d4(&self->anim168,0xffffffff);
    FUN_002175d4(&self->anim48,0xffffffff);
    FUN_0001f0f0(self,0);
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
