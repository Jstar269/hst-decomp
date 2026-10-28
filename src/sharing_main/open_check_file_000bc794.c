/* HSTMATCH module=hstp_trans_main.prx start=0x000bc794 end=0x000bc7fc symbol=FUN_000bc794 lang=c99 data=0x0037b308 */
/* Clone of src/eboot/open_check_file_000b9450.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x0037b308-0x0037b322) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the sign test written as >= 0 (bltzl); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0037b0cc;
extern void FUN_000143b0();
extern int FUN_0004cfac();
extern u32 FUN_0004d2c4();
extern void FUN_0004d31c();

void FUN_000bc794(u32 param_1,u32 param_2)
{
  int iVar1;
  u8 auStack_100 [256];
  
  FUN_000143b0(auStack_100,"data/camera/play_%02d.dat",param_2);
  iVar1 = FUN_0004cfac(auStack_100,1,1);
  if (iVar1 >= 0) {
    FUN_0004d31c(iVar1,&DAT_0037b0cc,0x120);
    FUN_0004d2c4(iVar1);
  }
}
