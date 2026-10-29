/* HSTMATCH module=hstp_trans_main.prx start=0x00198190 end=0x00198214 symbol=FUN_00198190 lang=c99 */
/* Clone of src/eboot/FUN_0018b9e0.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/render_target.h"

extern u8 DAT_003b2428;
extern RenderTarget *DAT_003ea86c;
extern void FUN_00000a00();
extern u32 * FUN_0001ed28();
extern int FUN_0005c688();
extern void FUN_00198e40();

/* Destructor: clears the global instance, releases the camera, then frees the object when delete_flag is positive. */
RenderTarget * FUN_00198190(RenderTarget *self,short delete_flag)
{
  if (self != (RenderTarget *)0x0) {
    self->vtable = &DAT_003b2428;
    FUN_00198e40();
    DAT_003ea86c = 0;
    if (self->camera != 0) {
      FUN_0005c688(self->camera,1);
      self->camera = 0;
    }
    FUN_0001ed28(self,0);
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
