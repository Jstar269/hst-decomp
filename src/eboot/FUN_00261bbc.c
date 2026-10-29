/* HSTMATCH module=EBOOT.BIN start=0x00261bbc end=0x00261c24 symbol=FUN_00261bbc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/target_items.h"

extern void FUN_000ffc70();

/* Resets the tint of the item's four objects (the third takes the item's own colour word). */
void FUN_00261bbc(TargetCtx *ctx,int index)
{
  TargetItem *item;
  
  item = &ctx->items[index];
  FUN_000ffc70(item->target,TARGET_TINT_NEUTRAL);
  FUN_000ffc70(item->unk0c,TARGET_TINT_NEUTRAL);
  FUN_000ffc70(item->unk10,item->unk18);
  FUN_000ffc70(item->unk14,TARGET_TINT_NEUTRAL);
}
