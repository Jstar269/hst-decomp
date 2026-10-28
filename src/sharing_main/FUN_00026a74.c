/* HSTMATCH module=hstp_trans_main.prx start=0x00026a74 end=0x00026a8c symbol=FUN_00026a74 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1gs); exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_000266d4();
extern void FUN_00026490();
extern void FUN_000291ec();

void FUN_00026a74(int *param_1,u8 (*param_2) [12],u32 param_3)
{
  FUN_000266d4(param_1,param_2,param_3,FUN_000291ec,FUN_00026490,'\x01');
}
