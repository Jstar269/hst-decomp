/* HSTMATCH module=hstp_trans_main.prx start=0x00297f98 end=0x00298064 symbol=FUN_00297f98 lang=c99 */
/* Clone of src/eboot/FUN_0028686c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b2f94;
extern void FUN_000009e4();
extern void FUN_00000a00();
extern int * FUN_001579f8();
extern void FUN_002983b4();
extern void FUN_0029abd0();

u32 * FUN_00297f98(u32 *param_1,short param_2)
{
  int *piVar1;
  u32 uStack_4;
  int local_8;
  u32 *local_c;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b2f94);
    if (param_1[4] != 0) {
      FUN_000009e4(*(int *)((int)param_1 + 16));
      param_1[4] = 0;
    }
    FUN_002983b4((int)param_1);
    if ((int *)param_1[1] != (int *)0x0) {
      FUN_001579f8((int *)param_1[1],1);
      param_1[1] = 0;
    }
    piVar1 = (int *)(param_1 + 0x19);
    if (((piVar1 != (int *)0x0) && (piVar1 != (int *)0x0)) && (piVar1 != (int *)0x0)) {
      local_c = param_1 + 0x1a;
      local_8 = param_1[0x1b];
      FUN_0029abd0(&uStack_4,piVar1,&local_8,&local_c);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
