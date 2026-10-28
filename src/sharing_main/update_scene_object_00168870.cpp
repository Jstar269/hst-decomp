/* HSTMATCH module=hstp_trans_main.prx start=0x00168870 end=0x00168a88 symbol=FUN_00168870 lang=c++ */
/* Hand-written reconstruction from the disassembly (adapted from the exact EBOOT twin src/eboot/update_scene_object_0015c2c8.cpp, same instruction shape: Sharing addresses substituted); exact match verified; names and types await human review. */
/* Ghidra pseudocode corrected by hand: object pointers use u8 offsets; global references and the float callback argument are typed to retail; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern char DAT_003859dc[];
extern char DAT_00385a04[];
extern char DAT_00385a20[];
extern u8 DAT_003b7ebc;
extern u8 DAT_003eaad8;
extern int FUN_00000bcc(...);
extern void FUN_000143b0(...);
extern int FUN_00014934(...);
extern u32 * FUN_000149a8(...);
extern void FUN_0001c684(void *, int, void *);
extern void FUN_0001c73c(void *);
extern u32 * FUN_000518d4(...);
extern void FUN_00051ad8(...);
extern void FUN_00051d38(u32, float);
extern void FUN_00166c04(...);
extern void FUN_001c16b4(void *, int);
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };

extern "C" void FUN_00168870(char *param_1,int param_2,int param_3)
{
  int iVar1;
  u32 uVar2;
  int *piVar3;
  
  FUN_000143b0(param_1 + 0x370,DAT_003859dc,param_2);
  FUN_0001c684(&DAT_003b7ebc,1,(void *)(param_1 + 0x370));
  if (param_2 == 0) {
    FUN_000143b0(param_1 + 0x370,DAT_00385a04,param_2);
    if (*(int *)(param_1 + 0x34) != 0) {
      iVar1 = FUN_00014934(param_1 + 0x70,param_1 + 0x370);
      if (iVar1 == 0) goto LAB_0015c49c;
    }
    piVar3 = *(int **)(param_1 + 0x34);
    if (piVar3 != (int *)0x0) {
      delete ((VC_0 *)(piVar3));
      *(u32 *)(param_1 + 0x34) = 0;
    }
    iVar1 = FUN_00000bcc(0x48);
    uVar2 = (u32)iVar1;
    if (iVar1 != 0) {
      uVar2 = (unsigned int)(FUN_000518d4(iVar1));
    }
    *(u32 *)(param_1 + 0x34) = uVar2;
    FUN_00051ad8(uVar2,param_1 + 0x370,0);
    FUN_00051d38(*(u32 *)(param_1 + 0x34),3000.0f);
    FUN_000149a8(param_1 + 0x70,param_1 + 0x370);
    *(u32 *)(param_1 + 0x40) = 0;
    *(u32 *)(param_1 + 0x44) = 0;
    *(u32 *)(param_1 + 0x48) = 0;
    *(u32 *)(param_1 + 0x4c) = 0x3f800000;
  }
  else {
    FUN_000143b0(param_1 + 0x370,DAT_00385a20,param_2 + -1);
    if (*(int *)(param_1 + 0x34) != 0) {
      iVar1 = FUN_00014934(param_1 + 0x70,param_1 + 0x370);
      if (iVar1 == 0) goto LAB_0015c49c;
    }
    piVar3 = *(int **)(param_1 + 0x34);
    if (piVar3 != (int *)0x0) {
      delete ((VC_1 *)(piVar3));
      *(u32 *)(param_1 + 0x34) = 0;
    }
    iVar1 = FUN_00000bcc(0x48);
    uVar2 = (u32)iVar1;
    if (iVar1 != 0) {
      uVar2 = (unsigned int)(FUN_000518d4(iVar1));
    }
    *(u32 *)(param_1 + 0x34) = uVar2;
    FUN_00051ad8(uVar2,param_1 + 0x370,0);
    FUN_00051d38(*(u32 *)(param_1 + 0x34),3000.0f);
    FUN_000149a8(param_1 + 0x70,param_1 + 0x370);
    *(u32 *)(param_1 + 0x40) = 0;
    *(u32 *)(param_1 + 0x44) = 0;
    *(u32 *)(param_1 + 0x48) = 0;
    *(u32 *)(param_1 + 0x4c) = 0x3f800000;
  }
LAB_0015c49c:
  FUN_00166c04(param_1);
  if (param_3 != 0) {
    FUN_001c16b4(&DAT_003eaad8,0);
  }
  FUN_0001c73c(&DAT_003b7ebc);
}
