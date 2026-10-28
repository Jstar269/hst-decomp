/* HSTMATCH module=hstp_trans_main.prx start=0x000c8b50 end=0x000c8b84 symbol=FUN_000c8b50 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003e1e04;
extern u32 FUN_000be1f4();
extern void FUN_00297918();

void FUN_000c8b50(int param_1)
{
  FUN_00297918(*(u32 *)(param_1 + 0x784));
  if (DAT_003e1e04 != 0) {
    FUN_000be1f4(DAT_003e1e04);
  }
}
