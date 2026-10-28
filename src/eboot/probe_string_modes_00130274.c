/* HSTMATCH module=EBOOT.BIN start=0x00130274 end=0x00130304 symbol=FUN_00130274 lang=c99 data=0x002db0e4 */
/* Clone of src/sharing_main/probe_string_modes_0013b82c.c (hstclone.py tag u3r2e): addresses substituted; exact match verified; names and types await human review. Data: its string literals (3 strings, 0x002db0e4-0x002db0ff) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: tested each string match as the nonzero path with one shared result; exact match verified; names and types await human review. */
#include "hst/types.h"

extern char * FUN_00014d64();

u32 FUN_00130274(u32 param_1,int param_2)
{
  int iVar1;
  u32 uVar2 = 0;
  if (param_2 == 0) {
    uVar2 = 0;
  } else {
    iVar1 = (int)FUN_00014d64(param_2,"TO_LONG");
    if (iVar1 != 0) {
      uVar2 = 0x32;
    } else {
      iVar1 = (int)FUN_00014d64(param_2,"TO_FINISH");
      if (iVar1 != 0) {
        uVar2 = 0x3c;
      } else {
        iVar1 = (int)FUN_00014d64(param_2,"NOLOOP");
        if (iVar1 != 0) uVar2 = 999;
      }
    }
  }
  return uVar2;
}
