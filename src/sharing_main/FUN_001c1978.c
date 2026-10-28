/* HSTMATCH module=hstp_trans_main.prx start=0x001c1978 end=0x001c1984 symbol=FUN_001c1978 lang=c99 */
/* Clone of src/eboot/FUN_001b3590.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001c1978(int *param_1,u8 param_2)
{
  *(u8 *)(*param_1 + 0x7dd) = param_2;
}
