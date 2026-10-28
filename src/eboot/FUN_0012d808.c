/* HSTMATCH module=EBOOT.BIN start=0x0012d808 end=0x0012d868 symbol=FUN_0012d808 lang=c99 data=0x002dad80 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128b); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002dad80-0x002dadad) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern void FUN_000143b0();
extern int FUN_0006517c();

void FUN_0012d808(int param_1,u32 param_2)
{
  u32 uVar1;
  
  uVar1 = FUN_0006517c(*(u32 *)(param_1 + 0x1398),*(u32 *)(param_1 + 0x1390),0);
  FUN_000143b0(param_2,"data/lobby/%s/setting/l%02d_r%02d_sedata.dat",uVar1,
               *(int *)(param_1 + 0x1390) + 1,*(int *)(param_1 + 0x1394) + 1);
}
