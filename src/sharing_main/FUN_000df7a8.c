/* HSTMATCH module=hstp_trans_main.prx start=0x000df7a8 end=0x000df814 symbol=FUN_000df7a8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003e1e88;
extern u8 DAT_003eaaf3;
extern u8 DAT_003eabd3;
extern u8 DAT_003eacf3;
extern void FUN_000df814();
extern void FUN_000df888();

void FUN_000df7a8(int param_1)
{
  if (DAT_003e1e88 != '\0') {
    DAT_003eaaf3 = 0;
    DAT_003eabd3 = 2;
    DAT_003eacf3 = 1;
    *(u32 *)(param_1 + 0xb4) = 1;
    *(u32 *)(param_1 + 0xc0) = 9;
  }
  FUN_000df814(param_1);
  FUN_000df888(param_1);
  *(u8 *)(param_1 + 0xb0) = 0;
}
