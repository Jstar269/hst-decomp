/* HSTMATCH module=EBOOT.BIN start=0x00043150 end=0x0004315c symbol=FUN_00043150 lang=c99 */
/* Clone of src/sharing_main/FUN_00043234.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00043150(int param_1,u32 *param_2)
{
  *(u32 *)(param_1 + 0x68) = *param_2;
}
