/* HSTMATCH module=hstp_trans_main.prx start=0x0027c50c end=0x0027c5f0 symbol=FUN_0027c50c lang=c++ data=0x003a6d70 */
/* Clone of src/eboot/FUN_0026b590.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (5 strings, 0x003a6d70-0x003a6dca) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_003b264c;
extern u8 DAT_003b2e5c;
extern int FUN_00108124(...);
extern u32 * FUN_0010873c(...);
extern int FUN_00109304(...);
extern void FUN_00109a44(...);
extern void FUN_0027c6a0(...);
}
struct VC_0 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void m(); };

extern "C" int * FUN_0027c50c(int *param_1)
{
  int iVar1;
  
  FUN_0010873c();
  *param_1 = (int)&DAT_003b264c;
  *(u8 *)(param_1 + 0x15) = 0;
  *(u8 *)((int)param_1 + 0x55) = 0;
  param_1[0x16] = 0;
  *param_1 = (int)&DAT_003b2e5c;
  FUN_00109a44(param_1,"data/menu/gamesharing/gamehsareing1layout.lay",0);
  iVar1 = FUN_00109304(param_1,"sharing1",0);
  param_1[0x18] = iVar1;
  iVar1 = FUN_00109304(param_1,"sharing2",0);
  param_1[0x19] = iVar1;
  iVar1 = FUN_00108124(param_1[0x18],"key040");
  param_1[0x16] = *(int *)(iVar1 + 0x20);
  iVar1 = FUN_00108124(param_1[0x19],"assign010");
  *(int *)(iVar1 + 0x24) = *(int *)(iVar1 + 0x28) + 1;
  param_1[0x1a] = 0;
  FUN_0027c6a0(param_1,0);
  ((VC_0 *)(param_1))->m();
  return param_1;
}
