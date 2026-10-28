/* HSTMATCH module=hstp_trans_main.prx start=0x00110294 end=0x00110370 symbol=FUN_00110294 lang=c99 */
/* Clone of src/eboot/init_0010a4d4.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: the function returns int (the stripped print call is declared int and its result is stored back into the checked value, which is returned: `if (r) r = print(fmt, r); return r;`), which keeps r in v0 and gives retail beqzl/move a1,v0 shape; exact match verified; names and types await human review. */
#include "hst/types.h"

extern char DAT_0037fba4[];
extern u32 * FUN_000114c0();
extern char * FUN_00014b74();
extern int FUN_00110268(const char *, ...);
extern void FUN_001a5d44();
extern int FUN_002c79c0();

int FUN_00110294(u32 *param_1,u32 param_2,int param_3)
{
  int iVar1;
  
  FUN_000114c0(param_1,0,0x2c4);
  *param_1 = 0x2c4;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0x11;
  param_1[4] = 0x13;
  param_1[5] = 0x12;
  param_1[6] = 0x10;
  FUN_001a5d44(param_1);
  param_1[0xd] = 1;
  if (param_3 == 1) {
    param_1[0x8f] = 0x90;
  }
  else if (param_3 == 2) {
    param_1[0x8f] = 0x80;
  }
  FUN_00014b74(param_1 + 0xf,param_2,0x1ff);
  *(u8 *)((int)param_1 + 0x23b) = 0;
  iVar1 = FUN_002c79c0(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_00110268(DAT_0037fba4,iVar1);
  }
  return iVar1;
}
