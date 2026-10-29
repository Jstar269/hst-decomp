/* HSTMATCH module=EBOOT.BIN start=0x00293a34 end=0x00293a74 symbol=FUN_00293a34 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/shop_items.h"

extern void FUN_000007f4();
extern void FUN_00293a74();
extern void FUN_00293acc();

/* Constructs the eight category vectors. */
ShopItemSet * FUN_00293a34(ShopItemSet *set)
{
  FUN_000007f4(set,FUN_00293acc,FUN_00293a74,sizeof(ShopVec),SHOP_VEC_COUNT);
  return set;
}
