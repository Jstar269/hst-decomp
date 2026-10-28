/* HSTMATCH module=hstp_trans_main.prx start=0x001daf64 end=0x001dafb4 symbol=FUN_001daf64 lang=c99 */
/* Clone of src/eboot/FUN_001cc830.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003e48b4;
extern void FUN_001db01c();
extern char FUN_002980f8();

void FUN_001daf64(int param_1)
{
  FUN_002980f8(DAT_003e48b4 + 0x1320,param_1 + 0x114,1);
  *(u8 *)(param_1 + 0x114) = 0;
  *(u8 *)(*(int *)(*(int *)(param_1 + 0x15c) + 0x20) + 0x6d) = 0;
  FUN_001db01c(param_1);
}
