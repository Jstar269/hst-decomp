/* HSTMATCH module=EBOOT.BIN start=0x0010ae20 end=0x0010aeb0 symbol=FUN_0010ae20 lang=c99 data=0x002d91c0 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. Data: its string literals (2 strings, 0x002d91c0-0x002d920f) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern void FUN_00012ad0();
extern u32 FUN_0004cad0();
extern u32 FUN_0010ad1c();

u32 FUN_0010ae20(u8 *param_1,u32 param_2)
{
  int iVar1;
  u32 uVar2;
  int local_4;
  
  iVar1 = FUN_0004cad0(param_2,&local_4,0x10,1);
  if (iVar1 == 0) {
    FUN_00012ad0("ERROR: Text::Load(%s): file not found.\n",param_2);
    uVar2 = 0;
  }
  else if (local_4 < 1) {
    FUN_00012ad0("ERROR: Text::Load(%s): file is empty.\n",param_2);
    uVar2 = 0;
  }
  else {
    *param_1 = 1;
    uVar2 = FUN_0010ad1c(param_1,iVar1);
  }
  return uVar2;
}
