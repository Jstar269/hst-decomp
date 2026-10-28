/* HSTMATCH module=hstp_trans_main.prx start=0x0013f3ec end=0x0013f468 symbol=FUN_0013f3ec lang=c99 data=0x00382954 */
/* Clone of src/eboot/FUN_00133da0.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x00382954-0x0038298a) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern u32 DAT_003e95e4;
extern void FUN_000143b0();
extern void FUN_0014e8ac();

u32 FUN_0013f3ec(int param_1,u32 param_2,u32 param_3)
{
  u32 uVar1;
  u8 auStack_100 [256];
  
  uVar1 = DAT_003e95e4;
  FUN_000143b0(auStack_100,"data/adcourt/%s/haichi/%s__haichi.i3m",DAT_003e95e4,DAT_003e95e4);
  FUN_0014e8ac(param_1 + 0x40,auStack_100,"data/adcourt/",uVar1,param_3,0,0);
  return 1;
}
