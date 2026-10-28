/* HSTMATCH module=EBOOT.BIN start=0x000be79c end=0x000be7b4 symbol=FUN_000be79c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003073cc;

u32 * FUN_000be79c(u32 *param_1)
{
  *param_1 = (unsigned int)(&DAT_003073cc);
  param_1[6] = 0;
  return param_1;
}
