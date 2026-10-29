/* HSTMATCH module=hstp_trans_main.prx start=0x002729e4 end=0x00272a4c symbol=FUN_002729e4 lang=c99 */
/* Clone of src/eboot/FUN_00261bbc.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/target_items.h"

extern void FUN_001055a4();

/* Resets the tint of the item's four objects (the third takes the item's own colour word). */
void FUN_002729e4(TargetCtx *ctx,int index)
{
  TargetItem *item;
  
  item = &ctx->items[index];
  FUN_001055a4(item->target,TARGET_TINT_NEUTRAL);
  FUN_001055a4(item->unk0c,TARGET_TINT_NEUTRAL);
  FUN_001055a4(item->unk10,item->unk18);
  FUN_001055a4(item->unk14,TARGET_TINT_NEUTRAL);
}
