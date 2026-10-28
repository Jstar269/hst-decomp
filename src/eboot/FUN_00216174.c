/* HSTMATCH module=EBOOT.BIN start=0x00216174 end=0x002161c4 symbol=FUN_00216174 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_0034a150;
extern void FUN_00216208();

u32 * FUN_00216174(u32 *param_1)
{
  DAT_0034a150 = (unsigned int)(param_1);
  FUN_00216208();
  *param_1 = 0x41c00000;
  param_1[1] = 0x3eb851ec;
  param_1[2] = 0x3d23d70a;
  return param_1;
}
