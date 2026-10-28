/* HSTMATCH module=EBOOT.BIN start=0x002955c8 end=0x002956e0 symbol=FUN_002955c8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag not recorded in lane candidate inputs/generated/FUN_002955c8.c) corrected by hand: typed the object and display-call arguments, and expressed the bounds guard as !(index < count); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002c0e18;
extern u8 DAT_002c0e1c;
extern u8 DAT_002c0e20;
extern u8 DAT_002cacf0;
extern void *DAT_003415ac;
extern void FUN_000143b0();
extern char * FUN_00014d64();
extern void FUN_00115088(void *, int, void *, int, int);
extern u8 * FUN_0018c9f4();

void FUN_002955c8(unsigned char *param_1,int param_2,char *param_3)
{
  int iVar1;
  int iVar2;
  u8 *puVar3;
  
  iVar1 = (int)(FUN_00014d64(param_3,&DAT_002cacf0));
  if (iVar1 == 0) {
    FUN_00115088(DAT_003415ac,param_2,param_3,0,0);
  }
  else {
    iVar1 = (int)(FUN_0018c9f4(0x13));
    iVar2 = *(int *)(param_1 + 0xeb44);
    if (*(int *)(iVar1 + 4) == 0) {
      puVar3 = &DAT_002c0e20;
    }
    else if (*(int *)(*(int *)(iVar1 + 8) + 8) < 0xb) {
      puVar3 = &DAT_002c0e1c;
    }
    else if ((iVar2 < 0) || !(iVar2 < *(int *)(*(int *)(iVar1 + 0xc) + 0x7c))) {
      puVar3 = &DAT_002c0e18;
    }
    else {
      puVar3 = *(u8 **)(*(int *)(*(int *)(iVar1 + 0xc) + 0x78) + iVar2 * 4);
    }
    FUN_000143b0(param_1 + 0x1a8,param_3,puVar3);
    FUN_00115088(DAT_003415ac,param_2,param_1 + 0x1a8,0,0);
  }
}
