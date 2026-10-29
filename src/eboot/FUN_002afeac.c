/* HSTMATCH module=EBOOT.BIN start=0x002afeac end=0x002aff04 symbol=FUN_002afeac lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/slot_array_obj.h"

extern void FUN_00000a00();
extern int * FUN_002b3c04();

/* Destructor of one slot vector; frees the memory itself when deleteFlag is positive. */
SlotVec * FUN_002afeac(SlotVec *vec,short deleteFlag)
{
  if (vec != 0) {
    if (vec != 0) {
      FUN_002b3c04(vec,0);
    }
    if (0 < deleteFlag) {
      FUN_00000a00(vec);
    }
  }
  return vec;
}
