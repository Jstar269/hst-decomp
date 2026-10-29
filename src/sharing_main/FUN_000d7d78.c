/* HSTMATCH module=hstp_trans_main.prx start=0x000d7d78 end=0x000d7e04 symbol=FUN_000d7d78 lang=c99 */
/* Clone of src/eboot/FUN_000d40b4.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/effect_set.h"

extern u32 DAT_003e19f0;
extern void FUN_0005ffd8();

/* For each of the slots whose player exists and whose flag is set, calls the helper on the member at +0x90 of the slot (the pointer walks from the object start, slots begin at +0x50). */
void FUN_000d7d78(EffectSet *self)
{
  int i;
  int player_off;
  char *slot;
  
  i = 0;
  player_off = 0;
  slot = (char *)self;
  do {
    if ((*(int *)(DAT_003e19f0 + player_off + 0x70) != 0) &&
       (self->unk7a0[i] != 0)) {
      FUN_0005ffd8(slot + 0xe0,0);
    }
    i += 1;
    player_off += 4;
    slot = slot + EFFECT_SLOT_SIZE;
  } while (i < EFFECT_SLOTS);
}
