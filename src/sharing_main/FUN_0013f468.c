/* HSTMATCH module=hstp_trans_main.prx start=0x0013f468 end=0x0013f4e4 symbol=FUN_0013f468 lang=c99 data=0x0038298c */
/* Clone of src/eboot/FUN_00133da0.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x0038298c-0x003829b0) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern u32 DAT_003e95e4;
extern char DAT_003825a4[];
extern void FUN_000143b0();
extern void FUN_0014e8ac();

u32 FUN_0013f468(int param_1,u32 param_2,u32 param_3)
{
  u32 uVar1;
  u8 auStack_100 [256];
  
  uVar1 = DAT_003e95e4;
  FUN_000143b0(auStack_100,"data/court/%s/haichi/%s__haichi.i3m",DAT_003e95e4,DAT_003e95e4);
  FUN_0014e8ac(param_1 + 0x40,auStack_100,DAT_003825a4,uVar1,param_3,0,0);
  return 1;
}
