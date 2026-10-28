/* HSTMATCH module=hstp_trans_main.prx start=0x001c6408 end=0x001c6440 symbol=FUN_001c6408 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003eaad8;
extern u32 FUN_001c0018();

void FUN_001c6408(int param_1)
{
  FUN_001c0018((int)&DAT_003eaad8,param_1 + 0x68);
  *(u32 *)(param_1 + 0x74) = 0;
  *(u8 *)(param_1 + 0x70) = 0;
}
