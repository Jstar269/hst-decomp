/* HSTMATCH module=EBOOT.BIN start=0x000ceaa4 end=0x000ceb1c symbol=FUN_000ceaa4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128b) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vtable_obj.h"

#define SUBOBJ_COUNT 3     /* sub-objects destroyed as an array */
#define SUBOBJ_SIZE 0x1b0  /* bytes per sub-object */
#define SUBOBJ_OFFSET 0x40 /* the array starts this far into the object */

extern u8 DAT_00307520;
extern void FUN_00000788();
extern void FUN_00000a00();
extern u32 * FUN_0001f0f0();
extern void FUN_00056cb0();

/* Deleting destructor: sets the class vtable, destroys the sub-object array, runs the base destructor, frees the object when delete_flag > 0. */
VtableObj * FUN_000ceaa4(VtableObj *self,short delete_flag)
{
  if (self != (VtableObj *)0x0) {
    self->vtable = &DAT_00307520;
    FUN_00000788((char *)self + SUBOBJ_OFFSET,FUN_00056cb0,SUBOBJ_SIZE,SUBOBJ_COUNT);
    FUN_0001f0f0(self,0);
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
