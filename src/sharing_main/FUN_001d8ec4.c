/* HSTMATCH module=hstp_trans_main.prx start=0x001d8ec4 end=0x001d8f00 symbol=FUN_001d8ec4 lang=c99 */
/* Clone of src/eboot/FUN_001ca8f0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_001d8f00();
extern u32 * FUN_00239cb8();
extern int FUN_00239ea4();

void FUN_001d8ec4(void)
{
  char *iVar1;
  u32 *puVar2;
  u32 auStack_1250 [1172];
  
  iVar1 = (char *)(FUN_00239ea4());
  puVar2 = FUN_00239cb8(auStack_1250);
  FUN_001d8f00((u32 *)(iVar1 + 0xa210),puVar2);
}
