/* HSTMATCH module=hstp_trans_main.prx start=0x0019ff00 end=0x0019ff68 symbol=FUN_0019ff00 lang=c99 */
/* Clone of src/eboot/FUN_000c7814.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vtable_obj.h"

extern void FUN_00000a00();
extern int FUN_001a2ea8();

/* Deleting destructor: runs the destructor body, frees the object when delete_flag > 0. */
VtableObj * FUN_0019ff00(VtableObj *self,short delete_flag)
{
  if (self != 0) {
    if (((self != 0) && (self != 0)) && (self != 0)) {
      FUN_001a2ea8(self,0);
    }
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
