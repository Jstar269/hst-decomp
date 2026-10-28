/* HSTMATCH module=EBOOT.BIN start=0x000fb074 end=0x000fb07c symbol=FUN_000fb074 lang=c99 */
/* Clone of src/eboot/FUN_0019075c.c (hstclone.py tag u1r1ee): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000fa9d4();

void FUN_000fb074(int param_1,u32 param_2,u32 param_3,u32 param_4, u32 param_5,u32 param_6,u32 param_7,u32 param_8)
{
  FUN_000fa9d4(*(int **)(param_1 + 0x3c),param_2,param_3,param_4,param_5,param_6,param_7,param_8);
}
