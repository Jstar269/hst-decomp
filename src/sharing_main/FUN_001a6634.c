/* HSTMATCH module=hstp_trans_main.prx start=0x001a6634 end=0x001a663c symbol=FUN_001a6634 lang=c99 */
/* Clone of src/eboot/FUN_0019075c.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001a6030();

void FUN_001a6634(int param_1,u32 param_2,u32 param_3,u32 param_4, u32 param_5,u32 param_6,u32 param_7,u32 param_8)
{
  FUN_001a6030(*(int **)(param_1 + 0x3c),param_2,param_3,param_4,param_5,param_6,param_7,param_8);
}
