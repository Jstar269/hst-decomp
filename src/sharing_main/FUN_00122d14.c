/* HSTMATCH module=hstp_trans_main.prx start=0x00122d14 end=0x00122d88 symbol=FUN_00122d14 lang=c99 */
/* Clone of src/eboot/FUN_00117cc4.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003e19f0;
extern void FUN_0001f4a0();
extern void FUN_00122dc0();
extern void FUN_00122e94();

void FUN_00122d14(int param_1)
{
  FUN_00122dc0(param_1,((*(int *)(param_1 + 0x5c) + 10) - (*(int *)(param_1 + 0x68) + 1) % 9) % 9,
               0xffffffff,0);
  FUN_00122e94(param_1);
  FUN_0001f4a0(DAT_003e19f0,0x16,0,0);
}
