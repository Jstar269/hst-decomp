/* HSTMATCH module=EBOOT.BIN start=0x000c77a8 end=0x000c7800 symbol=FUN_000c77a8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/vtable_obj.h"

extern void FUN_00000a00();
extern int * FUN_000d5a84();

/* Deleting destructor: runs the destructor body, frees the object when delete_flag > 0. */
VtableObj * FUN_000c77a8(VtableObj *self,short delete_flag)
{
  if (self != 0) {
    if (self != 0) {
      FUN_000d5a84(self,0);
    }
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
