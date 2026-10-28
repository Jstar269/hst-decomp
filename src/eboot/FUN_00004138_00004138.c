/* HSTMATCH module=EBOOT.BIN start=0x00004138 end=0x000041d0 symbol=FUN_00004138 lang=c99 */
/* Clone of src/sharing_main/FUN_00004138.c (hstclone.py tag u4r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: typed FUN_000030d0 as returning int; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00000a00();
extern int FUN_000030d0();
extern int FUN_000031b0();
extern void FUN_00003900();
extern int FUN_00003994();
extern u32 FUN_00003c50();

int FUN_00004138(int param_1,short param_2)
{
  int iVar1;
  u32 uVar2;
  u32 *puVar3;
  u32 uVar4;
  
  if (param_1 != 0) {
    iVar1 = FUN_000030d0();
    if (iVar1 != 0) {
      uVar2 = FUN_00003994(param_1);
      puVar3 = (u32 *)FUN_000031b0(param_1);
      uVar4 = FUN_00003c50(param_1);
      FUN_00003900(uVar2,*puVar3,uVar4);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
