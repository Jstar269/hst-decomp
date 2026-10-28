/* HSTMATCH module=hstp_trans_main.prx start=0x000f9010 end=0x000f9044 symbol=FUN_000f9010 lang=c99 */
/* Clone of src/eboot/FUN_000f3948.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_000f9010(int param_1)
{
  *(u32 *)(param_1 + 0x1e0) = *(u32 *)(*(int *)(param_1 + 0x128) + 0x24);
  *(u32 *)(param_1 + 0x1e4) = *(u32 *)(*(int *)(param_1 + 300) + 0x24);
  *(u32 *)(param_1 + 0x1e8) = *(u32 *)(*(int *)(param_1 + 0x138) + 0x24);
  *(u32 *)(param_1 + 0x1ec) = *(u32 *)(*(int *)(param_1 + 0x13c) + 0x24);
}
