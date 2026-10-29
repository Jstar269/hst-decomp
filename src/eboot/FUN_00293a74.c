/* HSTMATCH module=EBOOT.BIN start=0x00293a74 end=0x00293acc symbol=FUN_00293a74 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/shop_items.h"

extern void FUN_00000a00();
extern int * FUN_00294020();

/* Deleting destructor of one category vector. */
ShopVec * FUN_00293a74(ShopVec *vec,short flags)
{
  if (vec != 0) {
    if (vec != 0) {
      FUN_00294020(vec,0);
    }
    if (0 < flags) {
      FUN_00000a00(vec);
    }
  }
  return vec;
}
