/* HSTMATCH module=hstp_trans_main.prx start=0x000f707c end=0x000f70ac symbol=FUN_000f707c lang=c99 */
/* Clone of src/eboot/FUN_000f19b4.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00108f54();

void FUN_000f707c(int param_1)
{
  FUN_00108f54(param_1,1);
  *(u8 *)(param_1 + 0x78) = 1;
}
