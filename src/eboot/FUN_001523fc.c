/* HSTMATCH module=EBOOT.BIN start=0x001523fc end=0x00152484 symbol=FUN_001523fc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vec4_path.h"

extern u8 DAT_0030840c;
extern u8 DAT_00308c20;
extern void FUN_000009e4();
extern void FUN_00000a00();

/* Destructor of the point path: frees the point array, then the object when flags > 0. */
Vec4Path * FUN_001523fc(Vec4Path *self,short flags)
{
  Float4 *points;

  if (self != (Vec4Path *)0x0) {
    self->vtable = &DAT_00308c20;
    points = self->points;
    if (points != 0) {
      if (points != 0) {
        FUN_000009e4((char *)points + -0x10);
      }
      self->points = 0;
    }
    if (self != (Vec4Path *)0x0) {
      self->vtable = &DAT_0030840c;
    }
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
