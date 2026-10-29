/* HSTMATCH module=EBOOT.BIN start=0x00164474 end=0x001644bc symbol=FUN_00164474 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/stat_curve.h"

extern float DAT_003414d4[]; /* percent scale per level */

/* Scale the value at +0x34 by the percent for level 1 or 2; other levels leave it unchanged. */
float FUN_00164474(int self, int level)
{
  unsigned m = level - 1;
  float f = *(float *)(self + 0x34);

  if ((int)m >= 0 && m < STAT_LEVEL_COUNT)
    f = f * (DAT_003414d4[m] * 0.01f);
  return f;
}
