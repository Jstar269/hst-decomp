/* HSTMATCH module=hstp_trans_main.prx start=0x002b0200 end=0x002b0214 symbol=FUN_002b0200 lang=c99 */
/* Clone of src/eboot/FUN_002a0df4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_002b0200(int param_1,u16 param_2,u16 param_3,u16 param_4, u16 param_5)
{
  *(u16 *)(param_1 + 0xfc) = param_2;
  *(u16 *)(param_1 + 0xfe) = param_3;
  *(u16 *)(param_1 + 0x100) = param_4;
  *(u16 *)(param_1 + 0x102) = param_5;
}
