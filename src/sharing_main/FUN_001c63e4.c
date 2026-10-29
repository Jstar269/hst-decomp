/* HSTMATCH module=hstp_trans_main.prx start=0x001c63e4 end=0x001c6408 symbol=FUN_001c63e4 lang=c99 */
/* Clone of src/eboot/FUN_001b86f8.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/threshold_flags.h"

/* Clears both banks of threshold flags. */
void FUN_001c63e4(ThresholdFlags *flags)
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
