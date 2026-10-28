/* HSTMATCH module=EBOOT.BIN start=0x00192d44 end=0x00192d8c symbol=FUN_00192d44 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_00192b7c();
extern u32 * FUN_00192fb8();

u32 * FUN_00192d44(u32 *param_1)
{
  FUN_00192fb8(param_1 + 1);
  param_1[4] = 0;
  param_1[5] = 0;
  FUN_00192b7c(param_1 + 8);
  FUN_00192b7c(param_1 + 0x2c);
  *param_1 = 0;
  return param_1;
}
