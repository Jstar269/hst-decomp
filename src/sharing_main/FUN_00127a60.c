/* HSTMATCH module=hstp_trans_main.prx start=0x00127a60 end=0x00127ac4 symbol=FUN_00127a60 lang=c99 */
/* Clone of src/eboot/FUN_0011c828.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00000a00();
extern void FUN_00129090();

int FUN_00127a60(int param_1,short param_2)
{
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0xc) != 0) {
      FUN_00129090();
      FUN_00000a00(*(u32 *)(param_1 + 0xc));
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
