/* HSTMATCH module=EBOOT.BIN start=0x001b871c end=0x001b8754 symbol=FUN_001b871c lang=c99 */
/* Clone of src/sharing_main/FUN_001c6408.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0034179c;
extern u32 FUN_001b1f84();

void FUN_001b871c(int param_1)
{
  FUN_001b1f84((int)&DAT_0034179c,param_1 + 0x68);
  *(u32 *)(param_1 + 0x74) = 0;
  *(u8 *)(param_1 + 0x70) = 0;
}
