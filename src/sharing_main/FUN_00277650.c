/* HSTMATCH module=hstp_trans_main.prx start=0x00277650 end=0x00277668 symbol=FUN_00277650 lang=c99 */
/* Clone of src/eboot/FUN_00266748.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00277650(int param_1)
{
  if (*(int *)(param_1 + 0x70) != 0) {
    *(u32 *)(*(int *)(param_1 + 0x70) + 0xd0) = 0;
  }
}
