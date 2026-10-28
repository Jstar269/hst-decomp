/* HSTMATCH module=EBOOT.BIN start=0x0010061c end=0x001006b0 symbol=FUN_0010061c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2/v0) corrected by hand: the result is one variable `value = r; if (r == 0 || count <= 0) value = 0;` stored once (the if/else-with-two-stores form threads the jumps differently); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00014788(void *param_1, int *param_2);
extern void FUN_000149a8(void *param_1, u32 *param_2);
extern u32 FUN_0004cad0(char *param_1, int *param_2, int param_3, int param_4);
extern void FUN_000511c4(int param_1, u32 *param_2, u32 param_3);
extern void FUN_00051398(float param_1, int param_2);
extern int DAT_002d8a50;

void FUN_0010061c(int param_1,u32 *param_2,u32 param_3)
{
  u32 uVar1;
  u32 auStack_100 [64];
  int local_104;
  
  FUN_000511c4(param_1,param_2,param_3);
  FUN_00051398(100000.0f,param_1);
  FUN_000149a8(auStack_100,param_2);
  FUN_00014788(auStack_100,&DAT_002d8a50);
  uVar1 = FUN_0004cad0((char *)auStack_100,&local_104,0x10,1);
  {
    u32 value = uVar1;
    if (uVar1 == 0 || local_104 <= 0) value = 0;
    *(u32 *)(param_1 + 0x50) = value;
  }
}
