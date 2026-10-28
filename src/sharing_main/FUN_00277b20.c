/* HSTMATCH module=hstp_trans_main.prx start=0x00277b20 end=0x00277bc4 symbol=FUN_00277b20 lang=c99 */
/* Clone of src/eboot/FUN_00266ba4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b2de4;
extern void FUN_00000a00();
extern int * FUN_000ed9b8();
extern u32 * FUN_00297f98();

u32 * FUN_00277b20(u32 *param_1,short param_2)
{
  int *piVar1;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b2de4);
    if ((char *)param_1 + 0x80 != (char *)0) {
      piVar1 = (int *)(param_1 + 0x41);
      if ((piVar1 != (int *)0x0) && (piVar1 != (int *)0x0)) {
        FUN_000ed9b8(piVar1,0);
      }
      piVar1 = (int *)(param_1 + 0x3c);
      if ((piVar1 != (int *)0x0) && (piVar1 != (int *)0x0)) {
        FUN_000ed9b8(piVar1,0);
      }
    }
    FUN_00297f98(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
