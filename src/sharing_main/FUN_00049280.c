/* HSTMATCH module=hstp_trans_main.prx start=0x00049280 end=0x000492ac symbol=FUN_00049280 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00049280(int param_1)
{
  *(u32 *)(param_1 + 8) = 0xffffffff;
  *(u32 *)(param_1 + 0xc) = 0xffffffff;
  *(u32 *)(param_1 + 0x10) = 0xffffffff;
  *(u32 *)(param_1 + 0x14) = 0xffffffff;
  *(u32 *)(param_1 + 0x18) = 0xffffffff;
  *(u32 *)(param_1 + 0x1c) = 0xffffffff;
  *(u32 *)(param_1 + 0x20) = 0x477ffe00;
}
