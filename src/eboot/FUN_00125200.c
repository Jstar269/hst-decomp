/* HSTMATCH module=EBOOT.BIN start=0x00125200 end=0x0012520c symbol=FUN_00125200 lang=c99 */
/* Clone of src/eboot/FUN_0027c750.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_00340284;
extern void FUN_00131198();

void FUN_00125200(u32 param_1)
{
  FUN_00131198(param_1,DAT_00340284);
}
