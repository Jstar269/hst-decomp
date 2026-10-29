/* HSTMATCH module=EBOOT.BIN start=0x00133e1c end=0x00133e98 symbol=FUN_00133e1c lang=c99 data=0x002db72c */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002db72c-0x002db750) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"
#include "hst/court.h"

extern u32 DAT_003402a4;
extern char DAT_002db344[];
extern void FUN_000143b0();
extern void FUN_00143104();

u32 FUN_00133e1c(Court *court,u32 unused,u32 param_3)
{
  u32 court_name;
  u8 path[256];
  
  court_name = DAT_003402a4;
  FUN_000143b0(path,"data/court/%s/haichi/%s__haichi.i3m",DAT_003402a4,DAT_003402a4);
  FUN_00143104(&court->vptr1,path,DAT_002db344,court_name,param_3,0,0);
  return 1;
}
