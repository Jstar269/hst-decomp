/* HSTMATCH module=hstp_trans_main.prx start=0x00106f68 end=0x00107008 symbol=FUN_00106f68 lang=c99 */
/* Clone of src/eboot/FUN_00101590.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00107170(int *param_1,int param_2,int param_3,u32 param_4,u32 param_5, u32 param_6,u32 param_7);
extern void FUN_0010cf34(int *param_1,u32 param_2);

void FUN_00106f68(int param_1,u32 *param_2,u32 param_3)
{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x14) == 0) && (*(u32 *)(param_1 + 0x18) < param_3)) {
    FUN_0010cf34((int *)(param_1 + 0x10),(u32)(param_3));
  }
  iVar1 = 0;
  if (0 < (int)param_3) {
    do {
      FUN_00107170((int *)(param_1),(int)(*param_2),(int)(param_2[1]),(u32)((int)*(short *)(param_2 + 2)),(u32)((int)*(short *)((int)param_2 + 10)),(u32)((int)*(short *)(param_2 + 3)),(u32)(param_2[4]));
      iVar1 = iVar1 + 1;
      param_2 = param_2 + 5;
    } while (iVar1 < (int)param_3);
  }
}
