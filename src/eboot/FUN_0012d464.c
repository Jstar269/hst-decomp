/* HSTMATCH module=EBOOT.BIN start=0x0012d464 end=0x0012d550 symbol=FUN_0012d464 lang=c99 data=0x002dac60 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. Data: its string literals (5 strings, 0x002dac60-0x002dad54) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern void FUN_000143b0();
extern void FUN_00141718();
extern void FUN_0014189c();
extern void FUN_00141c3c();
extern void FUN_00141e70();
extern void FUN_0014613c();

void FUN_0012d464(u32 param_1,int param_2,int param_3)
{
  u8 auStack_100 [256];
  
  FUN_000143b0(auStack_100,"data/script/script_bin/lobby%02d/eventarea%02d.dat",param_2 + 1,param_3 + 1);
  FUN_00141718(param_1,auStack_100);
  FUN_000143b0(auStack_100,"data/script/script_bin/lobby%02d/route%02d.dat",param_2 + 1,param_3 + 1);
  FUN_0014613c(param_1,auStack_100);
  FUN_000143b0(auStack_100,"data/script/script_bin/lobby%02d/point%02d.dat",param_2 + 1,param_3 + 1);
  FUN_0014189c(param_1,auStack_100);
  FUN_000143b0(auStack_100,"data/script/script_bin/lobby%02d/item%02d.dat",param_2 + 1,param_3 + 1);
  FUN_00141c3c(param_1,auStack_100);
  FUN_000143b0(auStack_100,"data/script/script_bin/lobby%02d/patrol%02d.dat",param_2 + 1,param_3 + 1);
  FUN_00141e70(param_1,auStack_100);
}
