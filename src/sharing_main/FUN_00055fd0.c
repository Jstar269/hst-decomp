/* HSTMATCH module=hstp_trans_main.prx start=0x00055fd0 end=0x00055fdc symbol=FUN_00055fd0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1gs); exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_00055fd0(int param_1)
{
  return *(u32 *)(*(int *)(param_1 + 0x8c) + 0xc);
}
