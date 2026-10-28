/* HSTMATCH module=hstp_trans_main.prx start=0x002267ac end=0x00226820 symbol=FUN_002267ac lang=c99 */
/* Clone of src/eboot/FUN_00217704.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_002269c4();
extern void FUN_002269d0();
extern void FUN_002269dc();

void FUN_002267ac(u32 *param_1,int param_2)
{
  *param_1 = 0;
  param_1[1] = param_2;
  param_1[4] = 0;
  if (param_1[1] != 0) {
    *(short *)(param_1 + 2) = (short)(int)*(float *)(param_2 + 0x60);
    *(short *)((int)param_1 + 10) = (short)(int)*(float *)(param_2 + 100);
    *(u16 *)(param_1 + 3) = 0x80;
  }
  FUN_002269c4(param_1);
  FUN_002269d0(param_1);
  FUN_002269dc(param_1);
}
