/* HSTMATCH module=EBOOT.BIN start=0x00282214 end=0x00282518 symbol=FUN_00282214 lang=c99 */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned char bool;
typedef unsigned long long undefined8;
typedef int code();
#define true 1
#define false 0
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern undefined DAT_002c0e18;
extern undefined DAT_002c0e1c;
extern undefined DAT_002c0e20;
extern undefined4 DAT_00338ac4;
extern undefined4 DAT_003415a8;
extern undefined4 DAT_003415ac;
extern void FUN_000143b0();
extern void FUN_000149a8(void *, void *);
extern int FUN_00014a40(void *);
extern undefined4 * FUN_0008d0cc();
extern undefined1 * FUN_0008d0e4();
extern void FUN_0008d114();
extern void FUN_0008d2ec();
extern int FUN_000bbba4();
extern void FUN_000bd704();
extern int FUN_000bd8e0();
extern int FUN_000bd8f8();
extern void FUN_00114168();
extern undefined1 * FUN_0018c9f4();
extern void FUN_002805fc();

void FUN_00282214(char *param_1,int param_2)
{
  int index = param_2;
  int bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined *puVar5;
  uint uVar6;
  int iVar8;
  char *iVar9;
  int iVar7;
  undefined1 local_18 [24];
  
  if (*(undefined1 *)(param_1 + 0x38d4) != 0) {
    return;
  }
  iVar7 = index * 0x458;
  iVar8 = *(int *)(iVar7 + param_1 + 0xa74);
  if (iVar8 < 0) {
    iVar9 = (char *)(iVar7 + (int)param_1 + 0xa4c);
    iVar2 = FUN_00014a40(iVar9);
    if (iVar2 != 0) {
      FUN_000149a8(local_18,iVar9);
    }
    else {
      local_18[0] = 0;
    }
  }
  else {
    FUN_000149a8(local_18,param_1 + iVar8 * 0x458 + 0x1bac);
  }
  if (iVar8 < 0) {
    bVar1 = FUN_000bbba4(DAT_00338ac4,DAT_00338ac4 + 0x3e) < 0;
  }
  else {
    bVar1 = (*(undefined1 *)(iVar8 + param_1 + 0x90) != 0) ||
      (FUN_000bbba4(DAT_00338ac4,DAT_00338ac4 + 0x3e) < 0);
  }
  if (bVar1) {
    iVar8 = FUN_00014a40(local_18);
    if (iVar8 == 0) {
      FUN_002805fc(param_1 + 0x34d4,1,0,local_18);
    }
    else {
      uVar3 = FUN_000bd8e0(DAT_00338ac4,index);
      uVar4 = FUN_000bd8f8(DAT_00338ac4,index);
      FUN_002805fc(param_1 + 0x34d4,uVar3,uVar4,local_18);
    }
    *(undefined1 *)(param_1 + 0x38d4) = 1;
    goto LAB_00282460;
  }
  if (*(undefined1 *)(param_1 + 1) == 0) {
    iVar8 = FUN_00014a40(local_18);
    if (iVar8 != 0) {
      iVar8 = (int)(FUN_0018c9f4(0x11));
      if (*(int *)(iVar8 + 4) == 0) {
        puVar5 = &DAT_002c0e20;
      }
      else if (*(int *)(*(int *)(iVar8 + 8) + 8) < 0x11) {
        puVar5 = &DAT_002c0e1c;
      }
      else if (*(int *)(*(int *)(iVar8 + 0xc) + 0xc4) < 0xf) {
        puVar5 = &DAT_002c0e18;
      }
      else {
        puVar5 = *(undefined **)(*(int *)(*(int *)(iVar8 + 0xc) + 0xc0) + 0x38);
      }
      FUN_000143b0(param_1 + 0x34d4,puVar5,local_18);
      FUN_00114168(DAT_003415ac,6,param_1 + 0x34d4,0,0);
    }
LAB_00282448:
    *(undefined1 *)(param_1 + 0x38d4) = 0;
  }
  else {
    iVar8 = FUN_00014a40(local_18);
    if (iVar8 != 0) {
      uVar3 = FUN_000bd8e0(DAT_00338ac4,index);
      uVar4 = FUN_000bd8f8(DAT_00338ac4,index);
      FUN_002805fc(param_1 + 0x34d4,uVar3,uVar4,local_18);
      goto LAB_00282448;
    }
    *(undefined1 *)(param_1 + 0x38d4) = 0;
  }
  if (*(undefined1 *)(param_1 + 1) != 0) {
    *(undefined1 *)(param_1 + 0x38d4) = 1;
  }
LAB_00282460:
  FUN_000bd704(DAT_00338ac4,index);
  uVar6 = 0;
  iVar8 = (int)param_1 + iVar7;
  do {
    uVar6 = uVar6 + 1;
    *(undefined4 *)(iVar8 + 0x940) = 0xffffffff;
    iVar8 = iVar8 + 4;
  } while (uVar6 < 4);
  iVar7 = iVar7 + (int)param_1;
  *(undefined4 *)(iVar7 + 0x950) = 0xffffffff;
  *(undefined1 *)(iVar7 + 0x954) = 0;
  FUN_0008d114(iVar7 + 0x958);
  FUN_0008d2ec(iVar7 + 0x980);
  *(undefined1 *)(iVar7 + 0xa4c) = 0;
  FUN_0008d2ec(iVar7 + 0xaa0);
  FUN_0008d2ec(iVar7 + 0xbc0);
  *(undefined1 *)(iVar7 + 0xb6c) = 0;
  *(undefined1 *)(iVar7 + 0xc8c) = 0;
  FUN_0008d0e4(iVar7 + 0xa88,DAT_003415a8 + 4);
  FUN_0008d0cc(iVar7 + 0xa98,DAT_003415a8 + 0x18);
  return;
}
// Near miss: 143 of 193 words differ. The record clear loop matches; remaining differences start with s0/s1 coloring of param_2 and its scaled offset, then state-branch and call scheduling.
// Ruled out byte reads, char-pointer and struct-pointer forms, a local index copy, local declaration reorders, bool/int state flags, pointer-typed globals, if/OR/ternary guard forms, and a C++ build.
// near miss from lane km5 (unreviewed)
