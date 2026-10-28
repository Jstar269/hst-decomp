/* HSTMATCH module=hstp_trans_main.prx start=0x000d8ef0 end=0x000d8f34 symbol=FUN_000d8ef0 lang=c99 */
/* Clone of src/eboot/FUN_000d5200.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0808;
extern int FUN_00000bcc();

void FUN_000d8ef0(int param_1)
{
  u32 *puVar1;
  
  puVar1 = (u32 *)FUN_00000bcc(8);
  if (puVar1 != (u32 *)0x0) {
    *puVar1 = (unsigned int)(&DAT_003b0808);
    puVar1[1] = *(u32 *)(param_1 + 4);
  }
}
