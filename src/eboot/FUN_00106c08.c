/* HSTMATCH module=EBOOT.BIN start=0x00106c08 end=0x00106c18 symbol=FUN_00106c08 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002c1094;
extern void FUN_001006dc();

void FUN_00106c08(int param_1,u32 *param_2,u32 param_3)
{
  FUN_001006dc(param_1,param_2,(u32 *)&DAT_002c1094,param_3);
}
