/* HSTMATCH module=hstp_trans_main.prx start=0x000fd044 end=0x000fd0ac symbol=FUN_000fd044 lang=c99 */
/* Clone of src/eboot/FUN_000f7950.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0a48;
extern void FUN_00000a00();
extern void FUN_000fd524();
extern u32 * FUN_001087a8();

u32 * FUN_000fd044(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b0a48);
    FUN_000fd524(param_1,1);
    FUN_001087a8(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
