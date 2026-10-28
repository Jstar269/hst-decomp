/* HSTMATCH module=EBOOT.BIN start=0x00066240 end=0x00066280 symbol=FUN_00066240 lang=c99 */
/* Clone of src/eboot/FUN_0022995c.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00066cc8();

void FUN_00066240(u32 *param_1)
{
  if ((u32 *)param_1[1] != (u32 *)0x0) {
    FUN_00066cc8(param_1,(u32 *)param_1[1]);
    *param_1 = 0;
    param_1[1] = 0;
    param_1[3] = (unsigned int)(param_1 + 1);
  }
}
