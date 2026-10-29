/* HSTMATCH module=EBOOT.BIN start=0x000d40b4 end=0x000d4140 symbol=FUN_000d40b4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p1) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/effect_set.h"

extern u32 DAT_003386b0;
extern void FUN_0005f1e8();

/* For each of the slots whose player exists and whose flag is set, calls the helper on the member at +0x90 of the slot (the pointer walks from the object start, slots begin at +0x50). */
void FUN_000d40b4(EffectSet *self)
{
  int i;
  int player_off;
  char *slot;
  
  i = 0;
  player_off = 0;
  slot = (char *)self;
  do {
    if ((*(int *)(DAT_003386b0 + player_off + 0x70) != 0) &&
       (self->unk7a0[i] != 0)) {
      FUN_0005f1e8(slot + 0xe0,0);
    }
    i += 1;
    player_off += 4;
    slot = slot + EFFECT_SLOT_SIZE;
  } while (i < EFFECT_SLOTS);
}
