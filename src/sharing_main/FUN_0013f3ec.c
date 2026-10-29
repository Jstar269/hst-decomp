/* HSTMATCH module=hstp_trans_main.prx start=0x0013f3ec end=0x0013f468 symbol=FUN_0013f3ec lang=c99 data=0x00382954 */
/* Clone of src/eboot/FUN_00133da0.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. Data: its string literals (2 strings, 0x00382954-0x0038298a) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"
#include "hst/court.h"

extern u32 DAT_003e95e4;
extern void FUN_000143b0();
extern void FUN_0014e8ac();

u32 FUN_0013f3ec(Court *court,u32 unused,u32 param_3)
{
  u32 court_name;
  u8 path[256];
  
  court_name = DAT_003e95e4;
  FUN_000143b0(path,"data/adcourt/%s/haichi/%s__haichi.i3m",DAT_003e95e4,DAT_003e95e4);
  FUN_0014e8ac(&court->vptr1,path,"data/adcourt/",court_name,param_3,0,0);
  return 1;
}
