/* HSTMATCH module=EBOOT.BIN start=0x001b8f40 end=0x001b8f94 symbol=FUN_001b8f40 lang=c99 */
/* Clone of src/sharing_main/FUN_001c6c2c.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0034179c;
extern char DAT_002e99c3[];
extern void FUN_00000020();
extern void FUN_00000028();
extern void FUN_001b3a0c();

void FUN_001b8f40(u32 param_1,u32 param_2,u32 param_3)
{
  FUN_00000020(DAT_002e99c3 + 1);
  FUN_001b3a0c((int)&DAT_0034179c,param_2,param_3);
  FUN_00000028();
}
