/* HSTMATCH module=hstp_trans_main.prx start=0x002a51a0 end=0x002a51e0 symbol=FUN_002a51a0 lang=c99 */
/* Clone of src/eboot/FUN_00293b94.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/shop_items.h"

/* Returns the record at index of the category's vector, or null for an unused record. */
ShopRec * FUN_002a51a0(ShopItemSet *set,int category,int index)
{
  ShopRec *rec;
  
  rec = &set->vecs[category].data[index];
  if (rec->col[0] == SHOP_REC_EMPTY) {
    rec = (ShopRec *)0x0;
  }
  return rec;
}
