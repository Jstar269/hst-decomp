/* HSTMATCH module=hstp_trans_main.prx start=0x002be928 end=0x002be938 symbol=FUN_002be928 lang=c99 */
/* Clone of src/eboot/FUN_002af0a4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003ea8e8;
extern u64 FUN_001ca418(float param_1);

u64 FUN_002be928(void)
{
  u64 uVar1;
  
  uVar1 = FUN_001ca418(*(float *)(DAT_003ea8e8 + 0x1414));
  return uVar1;
}
