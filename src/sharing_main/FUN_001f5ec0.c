/* HSTMATCH module=hstp_trans_main.prx start=0x001f5ec0 end=0x001f5f08 symbol=FUN_001f5ec0 lang=c99 */
/* Clone of src/eboot/FUN_001e7ca8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00108f54();
extern void FUN_00226954();

void FUN_001f5ec0(int param_1)
{
  FUN_00108f54(*(u32 *)(param_1 + 0x250c),0);
  FUN_00226954(param_1 + 0x252c,0,0x80,10);
  *(u32 *)(param_1 + 0x2528) = 0x46;
}
