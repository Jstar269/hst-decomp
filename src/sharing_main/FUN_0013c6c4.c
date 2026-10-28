/* HSTMATCH module=hstp_trans_main.prx start=0x0013c6c4 end=0x0013c714 symbol=FUN_0013c6c4 lang=c99 */
/* Clone of src/eboot/FUN_0013110c.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0001ef14();
extern void FUN_0012f2d0();
extern u32 FUN_001303ec();

void FUN_0013c6c4(int param_1)
{
  u32 uVar1;
  
  FUN_0001ef14(*(u32 *)(param_1 + 0x80),1);
  FUN_0012f2d0(*(u32 *)(param_1 + 0x80),0,0);
  uVar1 = FUN_001303ec(*(u32 *)(param_1 + 0x80));
  *(u32 *)(param_1 + 0x88) = uVar1;
  *(u32 *)(param_1 + 0x8c) = 3;
}
