/* HSTMATCH module=hstp_trans_main.prx start=0x000cb2f4 end=0x000cb35c symbol=FUN_000cb2f4 lang=c99 */
/* Clone of src/eboot/FUN_000c7814.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vtable_obj.h"

extern void FUN_00000a00();
extern int FUN_000d9998();

/* Deleting destructor: runs the destructor body, frees the object when delete_flag > 0. */
VtableObj * FUN_000cb2f4(VtableObj *self,short delete_flag)
{
  if (self != 0) {
    if (((self != 0) && (self != 0)) && (self != 0)) {
      FUN_000d9998(self,0);
    }
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
