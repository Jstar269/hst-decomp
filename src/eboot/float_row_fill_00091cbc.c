/* HSTMATCH module=EBOOT.BIN start=0x00091cbc end=0x00091d90 symbol=FUN_00091cbc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256b) corrected by hand: the 7-float table as float pointer, the three float arguments of FUN_0006e094 (EABI float regs), the >= 0 test, and the local order (pointer before offset) for the saved registers; exact match verified; names and types await human review. */
#include "hst/types.h"
typedef int code();
extern float DAT_002d28b8;
extern int * FUN_000008d8(int *param_1,code *param_2,code *param_3,int param_4,u32 param_5);
extern int FUN_00000a90();
extern void FUN_0006e094(u32 *param_1,int param_2,float param_3,float param_4,float param_5);
extern void FUN_0006dfe4();
extern void FUN_0006e024();

void FUN_00091cbc(int param_1)
{
  int uVar1;
  u32 uVar4;
  float *pfVar3;
  int iVar2;
  float fVar5;
  float fVar6;

  if (*(int *)(param_1 + 0x24) == 0) {
    uVar1 = FUN_00000a90(0x48);
    uVar1 = (int)(FUN_000008d8((int *)(uVar1),(code *)(FUN_0006dfe4),(code *)(FUN_0006e024),8,7));
    *(int *)(param_1 + 0x24) = uVar1;
  }
  if (*(int *)(param_1 + 0x28) >= 0) {
    uVar4 = 0;
    pfVar3 = (float *)&DAT_002d28b8;
    iVar2 = 0;
    do {
      fVar6 = *pfVar3;
      if (*(int *)(param_1 + 0x28) == 0) {
        uVar1 = 2;
        fVar5 = 0.5f;
      }
      else {
        uVar1 = 1;
        fVar5 = 1.0f;
      }
      FUN_0006e094((u32 *)(*(int *)(param_1 + 0x24) + iVar2),uVar1,fVar6,fVar6,fVar5);
      uVar4 = uVar4 + 1;
      pfVar3 = pfVar3 + 1;
      iVar2 = iVar2 + 8;
    } while (uVar4 < 7);
  }
}
