/* HSTMATCH module=hstp_trans_main.prx start=0x001c8cc8 end=0x001c8cf4 symbol=FUN_001c8cc8 lang=c99 */
/* Clone of src/eboot/FUN_001baf80.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_001aa91c();

u8 FUN_001c8cc8(int param_1)
{
  int iVar1;
  
  iVar1 = FUN_001aa91c();
  return *(u8 *)(param_1 + iVar1 + 0x5c);
}
