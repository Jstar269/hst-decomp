/* HSTMATCH module=hstp_trans_main.prx start=0x00026abc end=0x00026ad4 symbol=FUN_00026abc lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1gs); exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_000266d4();
extern void FUN_00025f54();
extern void FUN_00029078();

void FUN_00026abc(int *param_1,u8 (*param_2) [12],u32 param_3)
{
  FUN_000266d4(param_1,param_2,param_3,FUN_00029078,FUN_00025f54,'\0');
}
