/* HSTMATCH module=hstp_trans_main.prx start=0x0026129c end=0x002612ac symbol=FUN_0026129c lang=c99 */
/* Clone of src/eboot/FUN_00250f48.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003a4908;

void FUN_0026129c(int param_1,u32 param_2)
{
  *(u32 *)(param_1 + 0x304) = param_2;
  DAT_003a4908 = param_2;
}
