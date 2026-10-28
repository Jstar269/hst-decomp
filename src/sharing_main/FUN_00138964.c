/* HSTMATCH module=hstp_trans_main.prx start=0x00138964 end=0x00138a50 symbol=FUN_00138964 lang=c99 data=0x00381dd4 */
/* Clone of src/eboot/FUN_0012d464.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. Data: its string literals (5 strings, 0x00381dd4-0x00381ec8) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern void FUN_000143b0();
extern void FUN_0014cd64();
extern void FUN_0014cee8();
extern void FUN_0014d288();
extern void FUN_0014d4bc();
extern void FUN_00151a24();

void FUN_00138964(u32 param_1,int param_2,int param_3)
{
  u8 auStack_100 [256];
  
  FUN_000143b0(auStack_100,"data/script/script_bin/lobby%02d/eventarea%02d.dat",param_2 + 1,param_3 + 1);
  FUN_0014cd64(param_1,auStack_100);
  FUN_000143b0(auStack_100,"data/script/script_bin/lobby%02d/route%02d.dat",param_2 + 1,param_3 + 1);
  FUN_00151a24(param_1,auStack_100);
  FUN_000143b0(auStack_100,"data/script/script_bin/lobby%02d/point%02d.dat",param_2 + 1,param_3 + 1);
  FUN_0014cee8(param_1,auStack_100);
  FUN_000143b0(auStack_100,"data/script/script_bin/lobby%02d/item%02d.dat",param_2 + 1,param_3 + 1);
  FUN_0014d288(param_1,auStack_100);
  FUN_000143b0(auStack_100,"data/script/script_bin/lobby%02d/patrol%02d.dat",param_2 + 1,param_3 + 1);
  FUN_0014d4bc(param_1,auStack_100);
}
