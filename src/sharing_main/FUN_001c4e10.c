/* HSTMATCH module=hstp_trans_main.prx start=0x001c4e10 end=0x001c4e84 symbol=FUN_001c4e10 lang=c99 */
/* Clone of src/eboot/FUN_001b7150.c (hstclone.py tag c32): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003eaad8;
extern void FUN_001c1a30();
extern void FUN_001c71e4();

void FUN_001c4e10(int param_1)
{
  u32 uStack_4;
  int local_8;
  int local_c;
  u32 uStack_10;
  int local_14;
  int local_18;
  
  local_c = param_1 + 0xf4;
  local_8 = *(int *)(param_1 + 0xf8);
  FUN_001c71e4(&uStack_4,(int *)(param_1 + 0xf0),&local_8,&local_c);
  local_18 = param_1 + 0x40;
  local_14 = *(int *)(param_1 + 0x44);
  FUN_001c71e4(&uStack_10,(int *)(param_1 + 0x3c),&local_14,&local_18);
  FUN_001c1a30((int *)&DAT_003eaad8);
}
