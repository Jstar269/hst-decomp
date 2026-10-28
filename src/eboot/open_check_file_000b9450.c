/* HSTMATCH module=EBOOT.BIN start=0x000b9450 end=0x000b94b8 symbol=FUN_000b9450 lang=c99 data=0x002d4a40 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the sign test written as >= 0 (bltzl); exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002d4a40-0x002d4a5a) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"

extern u8 DAT_002d4848;
extern void FUN_000143b0();
extern int FUN_0004ccb8();
extern u32 FUN_0004cfd0();
extern void FUN_0004d028();

void FUN_000b9450(u32 param_1,u32 param_2)
{
  int iVar1;
  u8 auStack_100 [256];
  
  FUN_000143b0(auStack_100,"data/camera/play_%02d.dat",param_2);
  iVar1 = FUN_0004ccb8(auStack_100,1,1);
  if (iVar1 >= 0) {
    FUN_0004d028(iVar1,&DAT_002d4848,0x120);
    FUN_0004cfd0(iVar1);
  }
}
