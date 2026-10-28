/* HSTMATCH module=EBOOT.BIN start=0x000ff4fc end=0x000ff548 symbol=FUN_000ff4fc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128b); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00307974;
extern int FUN_00010184();

u32 * FUN_000ff4fc(u32 *param_1,u32 param_2)
{
  u32 uVar1;
  
  *param_1 = (unsigned int)(&DAT_00307974);
  param_1[1] = 0;
  param_1[2] = param_2;
  param_1[3] = 0;
  param_1[4] = 0;
  uVar1 = FUN_00010184(0x40);
  param_1[1] = uVar1;
  return param_1;
}
