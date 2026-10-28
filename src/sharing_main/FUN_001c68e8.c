/* HSTMATCH module=hstp_trans_main.prx start=0x001c68e8 end=0x001c6940 symbol=FUN_001c68e8 lang=c99 */
/* Clone of src/eboot/FUN_001b8bfc.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001c71e4();
extern u32 * FUN_001c73f4();

int FUN_001c68e8(int param_1)
{
  u32 uStack_4;
  int local_8;
  int local_c;
  
  FUN_001c73f4((u32 *)param_1);
  *(u8 *)(param_1 + 0xc) = 0;
  local_c = param_1 + 4;
  local_8 = *(int *)(param_1 + 8);
  FUN_001c71e4(&uStack_4,(int *)param_1,&local_8,&local_c);
  *(u32 *)(param_1 + 0x10) = 9;
  return param_1;
}
