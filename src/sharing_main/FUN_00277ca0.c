/* HSTMATCH module=hstp_trans_main.prx start=0x00277ca0 end=0x00277d10 symbol=FUN_00277ca0 lang=c99 */
/* Clone of src/eboot/FUN_00266d24.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b2e40;
extern u32 DAT_003e95e0;
extern u32 * FUN_0001ec44();

u32 * FUN_00277ca0(u32 *param_1)
{
  FUN_0001ec44();
  *param_1 = (unsigned int)(&DAT_003b2e40);
  param_1[0xf] = 0;
  param_1[0x12] = 0;
  *(u8 *)(param_1 + 0x13) = 1;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  *(u8 *)(param_1 + 0x19) = 0;
  if (*(int *)(DAT_003e95e0 + 0x1364) == 6) {
    *(u8 *)((int)param_1 + 0x65) = 1;
  }
  else {
    *(u8 *)((int)param_1 + 0x65) = 0;
  }
  return param_1;
}
