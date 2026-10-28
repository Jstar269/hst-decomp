/* HSTMATCH module=hstp_trans_main.prx start=0x001106c0 end=0x001107c8 symbol=FUN_001106c0 lang=c99 */
/* Clone of src/eboot/init_0010a900.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0c) corrected by hand: the function returns int (the stripped print call is declared int and its result is stored back into the checked value, which is returned: `if (r) r = print(fmt, r); return r;`), which keeps r in v0 and gives retail beqzl/move a1,v0 shape; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0037fda0;
extern char DAT_0037fda4[];
extern char DAT_0037fdb0[];
extern u32 * FUN_000114c0();
extern char * FUN_00014b74();
extern int FUN_00110268(const char *, ...);
extern void FUN_001a5d44();
extern int FUN_002c7a50();

int FUN_001106c0(u32 *param_1,char *param_2,u32 param_3)
{
  int iVar1;
  
  FUN_000114c0(param_1,0,100);
  *param_1 = 100;
  param_1[1] = 0;
  param_1[2] = 0;
  param_1[3] = 0x11;
  param_1[4] = 0x13;
  param_1[5] = 0x12;
  param_1[6] = 0x10;
  FUN_001a5d44(param_1);
  param_1[3] = 0x27;
  param_1[4] = 0x29;
  param_1[5] = 0x28;
  param_1[6] = 0x26;
  FUN_00014b74(param_1 + 0xe,&DAT_0037fda0,8);
  param_1[0x15] = 1;
  param_1[0x16] = 2;
  param_1[0x17] = (unsigned int)(param_2);
  param_1[0x18] = param_3;
  param_1[0x14] = 0;
  FUN_00110268(DAT_0037fda4,(int)*param_2,(int)param_2[1],(int)param_2[2],(int)param_2[3]);
  iVar1 = FUN_002c7a50(param_1);
  if (iVar1 != 0) {
    iVar1 = FUN_00110268(DAT_0037fdb0,iVar1);
  }
  return iVar1;
}
