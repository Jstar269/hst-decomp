/* HSTMATCH module=EBOOT.BIN start=0x0004ae68 end=0x0004af60 symbol=FUN_0004ae68 lang=c99 data=0x002d08bc */
/* Clone of src/sharing_main/FUN_0004b044_0004b044.c (hstclone.py tag u3r2e): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002d08bc-0x002d08ca) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py tag v16) corrected by hand: reversed the status arms to preserve the retail logger branch; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002d0828;
extern u8 DAT_00311170;
extern bool FUN_0002b7fc();
extern u32 FUN_0002b8cc();
extern void FUN_00049194();
extern void FUN_000491cc();
extern void FUN_0004af60();
extern void FUN_0004afe0();
extern void FUN_0004b0f8();
extern u32 FUN_0004cad0();
extern void FUN_0004f010();

u32 FUN_0004ae68(int *param_1,u32 param_2,u32 param_3,u32 param_4, u32 param_5)
{
  int iVar1;
  
  FUN_0004af60(param_1);
  iVar1 = FUN_0004cad0(param_2,0,0x10,1);
  *param_1 = iVar1;
  if (iVar1 != 0) {
    FUN_00049194();
    iVar1 = FUN_0002b8cc(*param_1);
    FUN_000491cc();
    if (iVar1 != 0) {
      FUN_0004f010((int)&DAT_00311170,iVar1,"collision.cpp",0x158,&DAT_002d0828);
    } else {
      FUN_0002b7fc(*param_1,1);
      FUN_0004afe0(param_1,param_3);
      FUN_0004b0f8(param_1,param_4,param_5);
      return 1;
    }
  }
  FUN_0004af60(param_1);
  return 0;
}
