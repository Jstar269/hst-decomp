/* HSTMATCH module=EBOOT.BIN start=0x001cc190 end=0x001cc354 symbol=FUN_001cc190 lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (mechanical draft inputs/generated/FUN_001cc190.c, generator tag not recorded) corrected by hand: bounds test respelled as `iVar2 < 0 || !(iVar2 < size)`; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_002c0e18;
extern u8 DAT_002c0e1c;
extern u8 DAT_002c0e20;
extern u8 DAT_002ea308;
extern void FUN_0018a950(u32, u8 *);
extern u8 * FUN_0018c9f4(int);
extern void FUN_001cb5ec(int, void *, int, u32);
extern void FUN_001cd88c(int, int, int);
extern u8 * FUN_002294f4(int, u32, void *, int);
extern u32 FUN_002297d8(int, void *, int);
}

extern "C" void FUN_001cc190(int param_1,int param_2,u32 param_3,int param_4)
{
  int iVar1;
  int iVar2;
  register int iVar3;
  u8 *puVar4;
  u8 auStack_100 [256];
  
  if (param_2 != 0) {
    FUN_001cb5ec(param_1,auStack_100,param_2,param_3);
    if (param_4 < 0) {
      iVar2 = *(int *)(param_1 + 0x15c);
      iVar1 = (int)(FUN_002294f4(iVar2 + 0x34,*(u32 *)(iVar2 + 0x24),auStack_100,0));
      if (iVar1 != 0) {
        *(u8 *)(iVar2 + 99) = 0;
        *(u8 *)(iVar2 + 100) = 0;
        *(int *)(iVar2 + 0x68) = iVar1;
        *(u32 *)(iVar2 + 0x6c) = 0;
        *(u32 *)(iVar2 + 0x70) = 0;
        FUN_0018a950(*(u32 *)(iVar2 + 0x20),&DAT_002ea308);
        FUN_001cd88c(iVar2,2,1);
      }
      *(u32 *)(iVar2 + 0x74) = 0xffffffff;
      *(u32 *)(iVar2 + 0x78) = 0xffffffff;
      FUN_002297d8(iVar2 + 0x34,auStack_100,0);
    }
    else {
      iVar3 = *(int *)(*(int *)(param_1 + 0x4c) + param_4 * 4);
      iVar2 = *(int *)(iVar3 + 0x34);
      iVar1 = (int)(FUN_0018c9f4(7));
      if (*(int *)(iVar1 + 4) == 0) {
        puVar4 = &DAT_002c0e20;
      }
      else if (*(int *)(*(int *)(iVar1 + 8) + 8) < 1) {
        puVar4 = &DAT_002c0e1c;
      }
      else if (iVar2 < 0 || !(iVar2 < (*(int **)(iVar1 + 0xc))[1])) {
        puVar4 = &DAT_002c0e18;
      } else {
        puVar4 = *(u8 **)(**(int **)(iVar1 + 0xc) + iVar2 * 4);
      }
      iVar2 = *(int *)(param_1 + 0x15c);
      iVar1 = (int)(FUN_002294f4(iVar2 + 0x34,*(u32 *)(iVar2 + 0x24),auStack_100,0));
      if (iVar1 != 0) {
        *(u8 *)(iVar2 + 99) = 0;
        *(u8 *)(iVar2 + 100) = 0;
        *(int *)(iVar2 + 0x68) = iVar1;
        *(u32 *)(iVar2 + 0x6c) = 0;
        *(u32 *)(iVar2 + 0x70) = 0;
        FUN_0018a950(*(u32 *)(iVar2 + 0x20),puVar4);
        FUN_001cd88c(iVar2,2,1);
      }
      *(u32 *)(iVar2 + 0x74) = 0xffffffff;
      *(u32 *)(iVar2 + 0x78) = 0xffffffff;
      FUN_002297d8(iVar2 + 0x34,auStack_100,0);
      *(int *)(*(int *)(param_1 + 0x15c) + 0x5c) = iVar3;
    }
  }
}
