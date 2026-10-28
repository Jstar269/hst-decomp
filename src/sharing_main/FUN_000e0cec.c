/* HSTMATCH module=hstp_trans_main.prx start=0x000e0cec end=0x000e0d08 symbol=FUN_000e0cec lang=c99 */
/* Clone of src/eboot/FUN_000dcbe8.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_000e0cec(int param_1)
{
  if (*(u8 *)(param_1 + 0x44) != '\0') {
    *(u8 *)(param_1 + 0x66) = 1;
  }
}
