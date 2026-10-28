/* HSTMATCH module=hstp_trans_main.prx start=0x000d9890 end=0x000d98e0 symbol=FUN_000d9890 lang=c99 */
/* Clone of src/eboot/FUN_000d5ba0.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0808;
extern u8 DAT_003b081c;
extern int FUN_00000bcc();

void FUN_000d9890(int param_1)
{
  u32 *puVar1;
  
  puVar1 = (u32 *)FUN_00000bcc(8);
  if (puVar1 != (u32 *)0x0) {
    *puVar1 = (unsigned int)(&DAT_003b0808);
    puVar1[1] = *(u32 *)(param_1 + 4);
    *puVar1 = (unsigned int)(&DAT_003b081c);
  }
}
