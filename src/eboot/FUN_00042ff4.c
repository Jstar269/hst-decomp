/* HSTMATCH module=EBOOT.BIN start=0x00042ff4 end=0x00043004 symbol=FUN_00042ff4 lang=c99 */
/* Clone of src/sharing_main/FUN_000430d8.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00051398();

void FUN_00042ff4(char *param_1)
{
  FUN_00051398(*(u32 *)(param_1 + 0x19074));
}
