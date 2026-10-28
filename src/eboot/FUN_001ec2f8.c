/* HSTMATCH module=EBOOT.BIN start=0x001ec2f8 end=0x001ec35c symbol=FUN_001ec2f8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_0034a138;
extern void FUN_001ec3b8();
extern void FUN_001ec564();

u32 * FUN_001ec2f8(u32 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  DAT_0034a138 = (unsigned int)(param_1);
  FUN_001ec3b8();
  FUN_001ec564(param_1,0xb,0);
  param_1[4] = 0;
  *(u8 *)(param_1 + 7) = 0;
  param_1[5] = 0;
  *(u8 *)((int)param_1 + 0x1d) = 1;
  *(u8 *)((int)param_1 + 0x1e) = 0;
  return param_1;
}
