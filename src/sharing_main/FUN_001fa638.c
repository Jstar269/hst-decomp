/* HSTMATCH module=hstp_trans_main.prx start=0x001fa638 end=0x001fa69c symbol=FUN_001fa638 lang=c99 */
/* Clone of src/eboot/FUN_001ec2f8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003f3470;
extern void FUN_001fa6f8();
extern void FUN_001fa8a4();

u32 * FUN_001fa638(u32 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  DAT_003f3470 = (unsigned int)(param_1);
  FUN_001fa6f8();
  FUN_001fa8a4(param_1,0xb,0);
  param_1[4] = 0;
  *(u8 *)(param_1 + 7) = 0;
  param_1[5] = 0;
  *(u8 *)((int)param_1 + 0x1d) = 1;
  *(u8 *)((int)param_1 + 0x1e) = 0;
  return param_1;
}
