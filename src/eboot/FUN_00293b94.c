/* HSTMATCH module=EBOOT.BIN start=0x00293b94 end=0x00293bd4 symbol=FUN_00293b94 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/shop_items.h"

/* Returns the record at index of the category's vector, or null for an unused record. */
ShopRec * FUN_00293b94(ShopItemSet *set,int category,int index)
{
  ShopRec *rec;
  
  rec = &set->vecs[category].data[index];
  if (rec->col[0] == SHOP_REC_EMPTY) {
    rec = (ShopRec *)0x0;
  }
  return rec;
}
