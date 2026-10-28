/* HSTMATCH module=hstp_trans_main.prx start=0x000037f8 end=0x00003828 symbol=FUN_000037f8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00002fc0();
extern u32 FUN_00003828();

u32 FUN_000037f8(u32 param_1)
{
  FUN_00003828();
  FUN_00002fc0(param_1);
  return param_1;
}
