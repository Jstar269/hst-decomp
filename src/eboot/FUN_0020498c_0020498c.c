/* HSTMATCH module=EBOOT.BIN start=0x0020498c end=0x00204ac8 symbol=FUN_0020498c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: shared the allocation and table store across the null path and used a zeroed four-word local array; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002bc410;
extern u8 DAT_0034b340;
extern int FUN_00000bcc();
extern u32 * FUN_00091830(void *);
extern void FUN_00093434();
extern void FUN_0009345c();
extern void FUN_00093484(float param_1,int param_2);

int * FUN_0020498c(int *param_1,int param_2,u8 param_3)
{
  u32 *puVar1;
  int iVar2;
  u32 local_values[4];
  
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0;
  param_1[0xc] = 0;
  param_1[0xd] = 0;
  param_1[0xe] = 0;
  param_1[0xf] = 0;
  *(u8 *)(param_1 + 2) = param_3;
  *(u8 *)((int)param_1 + 9) = 0;
  param_1[1] = param_2;
  if (*(int *)(&DAT_0034b340 + param_2 * 4) == 0) {
    puVar1 = (u32 *)FUN_00000bcc(0xe0);
    if (puVar1 != (u32 *)0x0) {
      puVar1 = FUN_00091830(puVar1);
    }
    *(u32 **)(&DAT_0034b340 + param_1[1] * 4) = puVar1;
  }
  *param_1 = *(int *)(&DAT_0034b340 + param_1[1] * 4);
  local_values[0] = 0;
  local_values[1] = 0;
  local_values[2] = 0;
  local_values[3] = 0;
  FUN_0009345c(*param_1,local_values);
  FUN_00093484(1.0f,*param_1);
  FUN_00093434(*param_1,&DAT_002bc410);
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x10] = 0x3f800000;
  param_1[8] = 0;
  param_1[9] = 0;
  param_1[10] = 0;
  param_1[0xb] = 0x3f800000;
  *(u8 *)(param_1 + 0x1b) = 0;
  *(u8 *)(param_1 + 0x1d) = 0;
  *(u8 *)((int)param_1 + 0x75) = 0;
  *(u8 *)((int)param_1 + 0x76) = 0;
  *(u8 *)((int)param_1 + 0x77) = 0;
  *(u8 *)(param_1 + 0x1e) = 0;
  return param_1;
}
