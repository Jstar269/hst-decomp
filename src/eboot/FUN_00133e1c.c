/* HSTMATCH module=EBOOT.BIN start=0x00133e1c end=0x00133e98 symbol=FUN_00133e1c lang=c99 data=0x002db72c */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002db72c-0x002db750) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern u32 DAT_003402a4;
extern char DAT_002db344[];
extern void FUN_000143b0();
extern void FUN_00143104();

u32 FUN_00133e1c(int param_1,u32 param_2,u32 param_3)
{
  u32 uVar1;
  u8 auStack_100 [256];
  
  uVar1 = DAT_003402a4;
  FUN_000143b0(auStack_100,"data/court/%s/haichi/%s__haichi.i3m",DAT_003402a4,DAT_003402a4);
  FUN_00143104(param_1 + 0x40,auStack_100,DAT_002db344,uVar1,param_3,0,0);
  return 1;
}
