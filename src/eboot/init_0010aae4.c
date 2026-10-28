/* HSTMATCH module=EBOOT.BIN start=0x0010aae4 end=0x0010abe8 symbol=FUN_0010aae4 lang=c99 data=0x002d90b4 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: the function returns int (the stripped print call is declared int and its result is stored back into the checked value, which is returned: `if (r) r = print(fmt, r); return r;`), which keeps r in v0 and gives retail beqzl/move a1,v0 shape; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002d90b4-0x002d90e9) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern u32 * FUN_000114c0();
extern char * FUN_00014b74();
extern int FUN_0010a4a8(const char *, ...);
extern void FUN_00199280();
extern int FUN_002b7c10();

int FUN_0010aae4(u32 *param_1,u32 *param_2)
{
  int iVar1;
  
  FUN_000114c0(param_1,0,0x590);
  *param_1 = 0x590;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0x11;
  param_1[4] = 0x13;
  param_1[5] = 0x12;
  param_1[6] = 0x10;
  FUN_00199280(param_1);
  param_1[0xc] = 1;
  FUN_00014b74(param_1 + 0xd,*param_2,0xc);
  *(u8 *)(param_1 + 0x10) = 0;
  FUN_00014b74(param_1 + 0x11,param_2[1],0x13);
  *(u8 *)((int)param_1 + 0x57) = 0;
  FUN_00014b74(param_1 + 0x16,param_2[2],0x7f);
  *(u8 *)((int)param_1 + 0xd7) = 0;
  FUN_00014b74(param_1 + 0x36,param_2[3],0x7f);
  *(u8 *)((int)param_1 + 0x157) = 0;
  FUN_00014b74(param_1 + 0x56,param_2[4],0x3ff);
  *(u8 *)((int)param_1 + 0x557) = 0;
  *(u8 *)(param_1 + 0x156) = *(u8 *)(param_2 + 5);
  iVar1 = FUN_002b7c10(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_0010a4a8("ERROR: sceUtilityGamedataInstallInitStart(): 0x%08x\n",iVar1);
  }
  return iVar1;
}
