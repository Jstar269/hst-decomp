/* HSTMATCH module=hstp_trans_main.prx start=0x00210984 end=0x002109a4 symbol=FUN_00210984 lang=c99 */
/* Clone of src/eboot/FUN_002021b4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_00210984(float param_1,u8 *param_2)
{
  if (*param_2 != '\0') {
    *(float *)(param_2 + 0x14) = *(float *)(param_2 + 0x14) + param_1;
  }
}
