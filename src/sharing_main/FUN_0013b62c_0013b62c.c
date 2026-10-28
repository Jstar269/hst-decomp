/* HSTMATCH module=hstp_trans_main.prx start=0x0013b62c end=0x0013b72c symbol=FUN_0013b62c lang=c99 data=0x00382274 */
/* Clone of src/eboot/FUN_00130074_00130074.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (4 strings, 0x00382274-0x0038229e) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py tag v0c) corrected by hand: ordered result tests; exact match verified; names and types await human review. */
#include "hst/types.h"

extern char DAT_00382190[];
extern char DAT_0038219c[];
extern char DAT_00382228[];
extern char * FUN_00014d64();

u32 FUN_0013b62c(u32 param_1,int param_2)
{
  int result = 0;
  if (param_2 == 0) result = 0;
  else if (FUN_00014d64(param_2,"SERVICE") != 0) result = 1;
  else if (FUN_00014d64(param_2,"REPLAYSTART") != 0) result = 2;
  else if (FUN_00014d64(param_2,DAT_00382190) != 0) result = 3;
  else if (FUN_00014d64(param_2,"BOUND_FIRST") != 0) result = 4;
  else if (FUN_00014d64(param_2,DAT_0038219c) != 0) result = 5;
  else if (FUN_00014d64(param_2,"FINISHCAM") != 0) result = 6;
  else if (FUN_00014d64(param_2,DAT_00382228) != 0) result = 7;
  return result;
}
