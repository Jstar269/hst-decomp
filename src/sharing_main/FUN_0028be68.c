/* HSTMATCH module=hstp_trans_main.prx start=0x0028be68 end=0x0028be7c symbol=FUN_0028be68 lang=c99 */
/* Clone of src/eboot/FUN_0027ab84.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

bool FUN_0028be68(int param_1,int param_2)
{
  return *(int *)(param_2 + 0x10) < *(int *)(*(int *)(param_1 + 4) + 0x10);
}
