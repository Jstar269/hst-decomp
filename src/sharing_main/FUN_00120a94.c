/* HSTMATCH module=hstp_trans_main.prx start=0x00120a94 end=0x00120ac8 symbol=FUN_00120a94 lang=c99 */
/* Clone of src/eboot/FUN_00115b78.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001079b4();

void FUN_00120a94(int param_1,u16 param_2)
{
  FUN_001079b4();
  *(u16 *)(param_1 + 0x908) = param_2;
}
