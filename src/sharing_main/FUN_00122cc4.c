/* HSTMATCH module=hstp_trans_main.prx start=0x00122cc4 end=0x00122d14 symbol=FUN_00122cc4 lang=c99 */
/* Clone of src/eboot/FUN_00117c74.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003e95c4;
extern void FUN_00122dc0();
extern void FUN_00122e94();

void FUN_00122cc4(int param_1)
{
  FUN_00122dc0(param_1,8,0,0);
  FUN_00122e94(param_1);
  *(u8 *)(param_1 + 0x4c) = 0;
  *(u8 *)(*(int *)(DAT_003e95c4 + 0x80) + 0x79) = 1;
}
