/* HSTMATCH module=EBOOT.BIN start=0x00062990 end=0x000629c4 symbol=FUN_00062990 lang=c99 */
/* Clone of src/sharing_main/FUN_00063854.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00062a44();
extern void FUN_0007658c();

void FUN_00062990(int param_1)
{
  FUN_0007658c(*(u32 *)(param_1 + 4));
  FUN_00062a44(param_1,*(u32 *)(param_1 + 0xc));
}
