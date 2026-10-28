/* HSTMATCH module=hstp_trans_main.prx start=0x001d6148 end=0x001d61c4 symbol=FUN_001d6148 lang=c99 data=0x00392740 */
/* Clone of src/eboot/FUN_001c7cb4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00392740-0x0039276d) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern void FUN_000104e0();
extern void FUN_000143b0();
extern u32 FUN_0004cd8c();
extern void FUN_00132578();

int FUN_001d6148(u32 param_1,u32 param_2,int param_3,int param_4,u32 param_5, u32 param_6,u32 param_7,u32 param_8)
{
  u32 uVar1;
  char acStack_80 [128];
  int iStack_84;
  
  FUN_000143b0(acStack_80,"data/script/script_bin/lobby%02d/motlist.mld",param_2,param_4,param_5,
               param_6,param_7,param_8);
  uVar1 = FUN_0004cd8c(acStack_80,&iStack_84,0x10,1);
  if (param_4 != 0) {
    FUN_00132578(uVar1,param_3 - 1);
  }
  FUN_000104e0(uVar1);
  return param_4;
}
