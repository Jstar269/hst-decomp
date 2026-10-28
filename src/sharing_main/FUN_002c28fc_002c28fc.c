/* HSTMATCH module=hstp_trans_main.prx start=0x002c28fc end=0x002c2988 symbol=FUN_002c28fc lang=c99 data=0x003ac2d8 */
/* Clone of src/eboot/FUN_002b2e3c_002b2e3c.c (hstclone.py tag u4r4s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x003ac2d8-0x003ac2f8) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: typed the global and helper argument as float; exact match verified; names and types await human review. */
#include "hst/types.h"

extern float DAT_003ac028;
extern void FUN_00108e6c(float, int);
extern void FUN_001090f4();
extern void FUN_00109a44();

void FUN_002c28fc(int param_1)
{
  int iVar1;
  
  FUN_00109a44(param_1 + 0x3c,"data/menu/npc_list/npc_list.lay",0);
  FUN_001090f4(param_1 + 0x3c,0xfffffffe);
  FUN_00108e6c(DAT_003ac028,param_1 + 0x3c);
  iVar1 = 0;
  do {
    *(u32 *)(param_1 + 0x110) = 0;
    *(u32 *)(param_1 + 0x138) = 0;
    *(u32 *)(param_1 + 0x114) = 0;
    *(u32 *)(param_1 + 0x13c) = 0;
    *(u32 *)(param_1 + 0x118) = 0;
    *(u32 *)(param_1 + 0x140) = 0;
    *(u32 *)(param_1 + 0x11c) = 0;
    *(u32 *)(param_1 + 0x144) = 0;
    *(u32 *)(param_1 + 0x120) = 0;
    iVar1 = iVar1 + 5;
    *(u32 *)(param_1 + 0x148) = 0;
    param_1 = param_1 + 0x14;
  } while (iVar1 < 10);
}
