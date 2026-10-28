/* HSTMATCH module=EBOOT.BIN start=0x0008d264 end=0x0008d298 symbol=FUN_0008d264 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag probe1); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_000114c0();

u8 * FUN_0008d264(u8 *param_1)
{
  FUN_000114c0(param_1,0,1);
  *param_1 = 0;
  return param_1;
}
