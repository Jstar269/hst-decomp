/* HSTMATCH module=EBOOT.BIN start=0x0018b9e0 end=0x0018ba64 symbol=FUN_0018b9e0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/render_target.h"

extern u8 DAT_0030915c;
extern RenderTarget *DAT_0034152c;
extern void FUN_00000a00();
extern u32 * FUN_0001f0f0();
extern int FUN_0005ba00();
extern void FUN_0018c660();

/* Destructor: clears the global instance, releases the camera, then frees the object when delete_flag is positive. */
RenderTarget * FUN_0018b9e0(RenderTarget *self,short delete_flag)
{
  if (self != (RenderTarget *)0x0) {
    self->vtable = &DAT_0030915c;
    FUN_0018c660();
    DAT_0034152c = 0;
    if (self->camera != 0) {
      FUN_0005ba00(self->camera,1);
      self->camera = 0;
    }
    FUN_0001f0f0(self,0);
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
