/* HSTMATCH module=hstp_trans_main.prx start=0x001380b8 end=0x0013813c symbol=FUN_001380b8 lang=c99 */
/* Clone of src/eboot/FUN_0012cc4c.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b13d4;
extern u8 DAT_003b13f0;
extern u32 DAT_003da704;
extern u32 DAT_003e48b4;
extern int FUN_0005c2f8();
extern int FUN_0005c688();
extern int FUN_0005c700();
extern u32 * FUN_0014b1a4();
extern u32 * FUN_00297ebc();

u32 * FUN_001380b8(u32 *param_1)
{
  u8 auStack_2c0 [704];
  
  FUN_0014b1a4();
  FUN_00297ebc(param_1 + 0x4c8);
  *param_1 = (unsigned int)(&DAT_003b13d4);
  param_1[0x4c8] = (unsigned int)(&DAT_003b13f0);
  param_1[0x4e4] = 0;
  param_1[0x4e5] = 0;
  param_1[0x4e6] = 0;
  param_1[0x4e7] = 0;
  DAT_003e48b4 = (unsigned int)(param_1);
  FUN_0005c2f8(auStack_2c0);
  FUN_0005c700(DAT_003da704,auStack_2c0);
  FUN_0005c688(auStack_2c0,0xffffffff);
  return param_1;
}
