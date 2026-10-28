/* HSTMATCH module=hstp_trans_main.prx start=0x000970ec end=0x00097110 symbol=FUN_000970ec lang=c99 */
/* Clone of src/eboot/FUN_000950e0.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

bool FUN_000970ec(int param_1,int param_2)
{
  bool bVar1;
  
  if (*(u32 *)(param_1 + 0x1b0) < 3) {
    bVar1 = *(short *)(param_1 + 0x1b8) == param_2;
  }
  else {
    bVar1 = true;
  }
  return bVar1;
}
