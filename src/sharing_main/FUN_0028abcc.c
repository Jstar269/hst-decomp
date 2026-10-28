/* HSTMATCH module=hstp_trans_main.prx start=0x0028abcc end=0x0028ac8c symbol=FUN_0028abcc lang=c99 */
/* Clone of src/eboot/FUN_002798e8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003751d4;
extern void FUN_0001dc34();
extern void FUN_0001de88();

void FUN_0028abcc(int param_1)
{
  FUN_0001dc34(DAT_003751d4,0x2000);
  FUN_0001de88(DAT_003751d4,0x2000,1);
  FUN_0001dc34(DAT_003751d4,0x4000);
  FUN_0001de88(DAT_003751d4,0x4000,1);
  *(u8 *)(param_1 + 0x176) = 0;
  *(u8 *)(param_1 + 0x177) = 0;
  FUN_0001dc34(DAT_003751d4,0x20);
  FUN_0001de88(DAT_003751d4,0x20,1);
  FUN_0001dc34(DAT_003751d4,0x80);
  FUN_0001de88(DAT_003751d4,0x80,1);
  *(u8 *)(param_1 + 0x17a) = 0;
  *(u8 *)(param_1 + 0x17b) = 0;
}
