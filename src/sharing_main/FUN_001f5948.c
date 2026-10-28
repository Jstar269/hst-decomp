/* HSTMATCH module=hstp_trans_main.prx start=0x001f5948 end=0x001f5988 symbol=FUN_001f5948 lang=c99 */
/* Clone of src/eboot/FUN_001e7730.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_001fc5c8();

void FUN_001f5948(char *param_1)
{
  char *iVar1;
  
  iVar1 = (char *)(FUN_001fc5c8());
  *(int *)(param_1 + 0x2350) = *(int *)(iVar1 + 0x8178) + 4;
  *(u32 *)(param_1 + 0x2354) = 0xf;
}
