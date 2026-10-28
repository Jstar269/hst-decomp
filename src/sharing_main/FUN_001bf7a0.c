/* HSTMATCH module=hstp_trans_main.prx start=0x001bf7a0 end=0x001bf834 symbol=FUN_001bf7a0 lang=c99 */
/* Clone of src/eboot/FUN_001b177c.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00391314;
extern u8 DAT_0039131c;
extern u8 DAT_00391320;
extern u32 * FUN_00014788();
extern u32 * FUN_000149a8();
extern char * FUN_00014b74();
extern int FUN_00014cfc();
extern char * FUN_00014d64();

void FUN_001bf7a0(u32 param_1)
{
  u8 *puVar1;
  int iVar2;
  u8 auStack_10 [16];
  
  puVar1 = (u8 *)FUN_00014cfc(param_1,0x2e);
  if (puVar1 != (u8 *)0x0) {
    FUN_000149a8(auStack_10,puVar1);
    *puVar1 = 0;
    FUN_00014788(param_1,&DAT_00391314);
    FUN_00014788(param_1,auStack_10);
  }
  iVar2 = (int)(FUN_00014d64(param_1,&DAT_0039131c));
  if (iVar2 != 0) {
    FUN_00014b74(iVar2,&DAT_00391320,3);
  }
}
