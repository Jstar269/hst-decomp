/* HSTMATCH module=EBOOT.BIN start=0x0014dd38 end=0x0014de24 symbol=FUN_0014dd38 lang=c99 rodata=0x002c1a28 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag u1ge); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003402f4;
extern u8 DAT_00340374;
extern int FUN_0022a940();
extern u8 * FUN_0022a958();
extern int FUN_0022a970();
extern int FUN_0022a98c();

float FUN_0014dd38(int param_1,int param_2)
{
  int *piVar1;
  float *pfVar2;
  float fVar3;
  
  fVar3 = 0.0f;
  switch(*(u32 *)(param_1 + 8)) {
  case 0:
    piVar1 = (int *)FUN_0022a940(*(int *)(param_1 + 0xc));
    fVar3 = (float)*piVar1;
    break;
  case 1:
    pfVar2 = (float *)FUN_0022a958(*(int *)(param_1 + 0xc));
    fVar3 = *pfVar2;
    break;
  case 2:
    piVar1 = (int *)FUN_0022a970(*(int *)(param_1 + 0xc));
    fVar3 = (float)*piVar1;
    break;
  case 3:
    pfVar2 = (float *)FUN_0022a98c(*(int *)(param_1 + 0xc));
    fVar3 = *pfVar2;
    break;
  case 4:
    fVar3 = (float)*(int *)(param_2 + *(int *)(param_1 + 0xc) * 4 + 0xc);
    break;
  case 5:
    fVar3 = *(float *)(param_2 + *(int *)(param_1 + 0xc) * 4 + 0x10c);
    break;
  case 8:
    fVar3 = (float)*(int *)(*(int *)(param_1 + 0xc) * 4 + (int)&DAT_003402f4);
    break;
  case 9:
    fVar3 = *(float *)(*(int *)(param_1 + 0xc) * 4 + (int)&DAT_00340374);
  }
  return fVar3;
}
