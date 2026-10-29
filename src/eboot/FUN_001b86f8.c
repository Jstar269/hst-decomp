/* HSTMATCH module=EBOOT.BIN start=0x001b86f8 end=0x001b871c symbol=FUN_001b86f8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/threshold_flags.h"

/* Clears both banks of threshold flags. */
void FUN_001b86f8(ThresholdFlags *flags)
{
  flags->low[0] = 0;
  flags->high[0] = 0;
  flags->low[1] = 0;
  flags->high[1] = 0;
  flags->low[2] = 0;
  flags->high[2] = 0;
  flags->low[3] = 0;
  flags->high[3] = 0;
}
