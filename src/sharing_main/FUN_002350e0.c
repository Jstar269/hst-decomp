/* HSTMATCH module=hstp_trans_main.prx start=0x002350e0 end=0x002350ec symbol=FUN_002350e0 lang=c99 */
/* Clone of src/eboot/FUN_00225b6c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000fc200();

void FUN_002350e0(int param_1)
{
  FUN_000fc200(*(u32 *)(*(int *)(param_1 + 0x3c) + 0x30));
}
