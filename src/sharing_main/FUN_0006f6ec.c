/* HSTMATCH module=hstp_trans_main.prx start=0x0006f6ec end=0x0006f75c symbol=FUN_0006f6ec lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_003daf6c;
extern void FUN_00000a00();
extern void FUN_000700fc();

int FUN_0006f6ec(int param_1,short param_2)
{
  if (param_1 != 0) {
    if ((DAT_003daf6c != 0) && (*(int *)(param_1 + 4) != 0)) {
      FUN_000700fc(DAT_003daf6c + 0xc,*(int *)((int)param_1 + 4));
      *(u32 *)(param_1 + 4) = 0;
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
