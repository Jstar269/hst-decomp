/* HSTMATCH module=hstp_trans_main.prx start=0x001c2274 end=0x001c2280 symbol=FUN_001c2274 lang=c99 */
/* Clone of src/eboot/FUN_001b4130.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/slot_fade.h"

/* The level last set. */
float FUN_001c2274(SlotFadeTable **ctx)
{
  return (*ctx)->level;
}
