/* HSTMATCH module=hstp_trans_main.prx start=0x0006c1b4 end=0x0006c1f8 symbol=FUN_0006c1b4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000006e8();
extern void FUN_000009e4();
extern void FUN_00057904();

void FUN_0006c1b4(u32 *param_1)
{
  FUN_000009e4(param_1[2]);
  param_1[2] = 0;
  FUN_000006e8(param_1[1],FUN_00057904);
  param_1[1] = 0;
  *param_1 = 0;
}
