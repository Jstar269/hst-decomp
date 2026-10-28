/* HSTMATCH module=EBOOT.BIN start=0x00063478 end=0x000634a0 symbol=FUN_00063478 lang=c99 */
/* Clone of src/sharing_main/FUN_0006433c.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00311170;
extern u32 FUN_00050534();
extern void FUN_00051398();

void FUN_00063478(int param_1)
{
  FUN_00051398(*(u32 *)(param_1 + 4));
  FUN_00050534((int)&DAT_00311170);
}
