/* HSTMATCH module=EBOOT.BIN start=0x00133da0 end=0x00133e1c symbol=FUN_00133da0 lang=c99 data=0x002db6f4 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. Data: its string literals (2 strings, 0x002db6f4-0x002db72a) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"
#include "hst/court.h"

extern u32 DAT_003402a4;
extern void FUN_000143b0();
extern void FUN_00143104();

u32 FUN_00133da0(Court *court,u32 unused,u32 param_3)
{
  u32 court_name;
  u8 path[256];
  
  court_name = DAT_003402a4;
  FUN_000143b0(path,"data/adcourt/%s/haichi/%s__haichi.i3m",DAT_003402a4,DAT_003402a4);
  FUN_00143104(&court->vptr1,path,"data/adcourt/",court_name,param_3,0,0);
  return 1;
}
