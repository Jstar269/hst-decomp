/* HSTMATCH module=hstp_trans_main.prx start=0x00070138 end=0x0007017c symbol=FUN_00070138 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000006e8();
extern void FUN_000009e4();
extern void FUN_0005bbd8();

void FUN_00070138(u32 *param_1)
{
  FUN_000009e4(param_1[2]);
  param_1[2] = 0;
  FUN_000006e8(param_1[1],FUN_0005bbd8);
  param_1[1] = 0;
  *param_1 = 0;
}
