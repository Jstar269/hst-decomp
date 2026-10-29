/* HSTMATCH module=hstp_trans_main.prx start=0x000d26a0 end=0x000d2718 symbol=FUN_000d26a0 lang=c99 */
/* Clone of src/eboot/FUN_000ceaa4.c (hstclone.py tag x11): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vtable_obj.h"

#define SUBOBJ_COUNT 3     /* sub-objects destroyed as an array */
#define SUBOBJ_SIZE 0x1b0  /* bytes per sub-object */
#define SUBOBJ_OFFSET 0x40 /* the array starts this far into the object */

extern u8 DAT_003b07ec;
extern void FUN_00000788();
extern void FUN_00000a00();
extern u32 * FUN_0001ed28();
extern void FUN_00057904();

/* Deleting destructor: sets the class vtable, destroys the sub-object array, runs the base destructor, frees the object when delete_flag > 0. */
VtableObj * FUN_000d26a0(VtableObj *self,short delete_flag)
{
  if (self != (VtableObj *)0x0) {
    self->vtable = &DAT_003b07ec;
    FUN_00000788((char *)self + SUBOBJ_OFFSET,FUN_00057904,SUBOBJ_SIZE,SUBOBJ_COUNT);
    FUN_0001ed28(self,0);
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
