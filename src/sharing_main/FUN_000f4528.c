/* HSTMATCH module=hstp_trans_main.prx start=0x000f4528 end=0x000f4560 symbol=FUN_000f4528 lang=c99 */
/* Clone of src/eboot/FUN_000eee60.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000f4590();
extern void FUN_00109024();

void FUN_000f4528(int param_1)
{
  *(u32 *)(param_1 + 0x6c) = 0;
  *(u32 *)(param_1 + 0x70) = 0;
  FUN_000f4590();
  FUN_00109024(param_1,0);
}
