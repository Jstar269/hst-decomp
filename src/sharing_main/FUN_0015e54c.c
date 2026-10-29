/* HSTMATCH module=hstp_trans_main.prx start=0x0015e54c end=0x0015e5d4 symbol=FUN_0015e54c lang=c99 */
/* Clone of src/eboot/FUN_001523fc.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vec4_path.h"

extern u8 DAT_003b16d8;
extern u8 DAT_003b1eec;
extern void FUN_000009e4();
extern void FUN_00000a00();

/* Destructor of the point path: frees the point array, then the object when flags > 0. */
Vec4Path * FUN_0015e54c(Vec4Path *self,short flags)
{
  Float4 *points;

  if (self != (Vec4Path *)0x0) {
    self->vtable = &DAT_003b1eec;
    points = self->points;
    if (points != 0) {
      if (points != 0) {
        FUN_000009e4((char *)points + -0x10);
      }
      self->points = 0;
    }
    if (self != (Vec4Path *)0x0) {
      self->vtable = &DAT_003b16d8;
    }
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
