/* HSTMATCH module=hstp_trans_main.prx start=0x00138ca8 end=0x00138d08 symbol=FUN_00138ca8 lang=c99 data=0x00381ec8 */
/* Clone of src/eboot/FUN_0012d7a8.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00381ec8-0x00381ef1) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern void FUN_000143b0();
extern int FUN_000661a8();

void FUN_00138ca8(int param_1,u32 param_2)
{
  u32 uVar1;
  
  uVar1 = FUN_000661a8(*(u32 *)(param_1 + 0x1398),*(u32 *)(param_1 + 0x1390),0);
  FUN_000143b0(param_2,"data/lobby/%s/setting/l%02d_r%02d_se.csv",uVar1,
               *(int *)(param_1 + 0x1390) + 1,*(int *)(param_1 + 0x1394) + 1);
}
