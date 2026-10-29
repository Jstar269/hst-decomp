/* HSTMATCH module=hstp_trans_main.prx start=0x002a5040 end=0x002a5080 symbol=FUN_002a5040 lang=c99 */
/* Clone of src/eboot/FUN_00293a34.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/shop_items.h"

extern void FUN_000007f4();
extern void FUN_002a5080();
extern void FUN_002a50d8();

/* Constructs the eight category vectors. */
ShopItemSet * FUN_002a5040(ShopItemSet *set)
{
  FUN_000007f4(set,FUN_002a50d8,FUN_002a5080,sizeof(ShopVec),SHOP_VEC_COUNT);
  return set;
}
