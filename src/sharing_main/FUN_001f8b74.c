/* HSTMATCH module=hstp_trans_main.prx start=0x001f8b74 end=0x001f8b80 symbol=FUN_001f8b74 lang=c99 */
/* Clone of src/eboot/FUN_001ea8d0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001f8b74(int *param_1,u8 param_2)
{
  *(u8 *)(*param_1 + 0x424) = param_2;
}
