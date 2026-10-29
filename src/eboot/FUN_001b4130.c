/* HSTMATCH module=EBOOT.BIN start=0x001b4130 end=0x001b413c symbol=FUN_001b4130 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/slot_fade.h"

/* The level last set. */
float FUN_001b4130(SlotFadeTable **ctx)
{
  return (*ctx)->level;
}
