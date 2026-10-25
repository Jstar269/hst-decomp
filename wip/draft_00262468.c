/* HSTMATCH module=EBOOT.BIN start=0x00262468 end=0x00262888 symbol=FUN_00262468 lang=c99 */
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
extern undefined4 DAT_002cfc8c;
extern undefined * DAT_00338ac4;
extern undefined4 DAT_003415a8;
extern undefined4 DAT_003415ac;
extern char DAT_002fde20[];
extern void FUN_0001dfe8();
extern void FUN_0001e23c();
extern undefined4 * FUN_0008d0cc();
extern undefined1 * FUN_0008d0e4();
extern void FUN_0008d114();
extern void FUN_0008d2ec();
extern void FUN_000ffb3c();
extern void FUN_00103540();
extern void FUN_00103628();
extern void FUN_001037c8();
extern void FUN_0010d4a8();
extern void FUN_00114168();
extern undefined1 * FUN_0018c9f4();
extern void FUN_001b3ce8();
extern void FUN_00262888();
extern void FUN_002628b4();

void FUN_00262468(int *param_1)
{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined *puVar5;
  undefined4 *puVar6;
  int iVar7;
  
  bVar1 = true;
  if ((DAT_00338ac4 != 0) && (*(char *)(DAT_00338ac4 + 0x178) == '\0')) {
    bVar1 = false;
  }
  if (bVar1) {
    iVar7 = 0;
    iVar4 = 0;
    do {
      uVar3 = 0;
      iVar2 = param_1[400] + iVar4;
      puVar6 = (undefined4 *)(iVar2 + 0x940);
      do {
        uVar3 = uVar3 + 1;
        *puVar6 = 0xffffffff;
        puVar6 = puVar6 + 1;
      } while (uVar3 < 4);
      *(undefined4 *)(iVar2 + 0x950) = 0xffffffff;
      *(undefined1 *)(iVar2 + 0x954) = 0;
      FUN_0008d114(iVar2 + 0x958);
      FUN_0008d2ec(iVar2 + 0x980);
      *(undefined1 *)(iVar2 + 0xa4c) = 0;
      FUN_0008d2ec(iVar2 + 0xaa0);
      FUN_0008d2ec(iVar2 + 0xbc0);
      *(undefined1 *)(iVar2 + 0xb6c) = 0;
      *(undefined1 *)(iVar2 + 0xc8c) = 0;
      FUN_0008d0e4(iVar2 + 0xa88,DAT_003415a8 + 4);
      FUN_0008d0cc(iVar2 + 0xa98,DAT_003415a8 + 0x18);
      uVar3 = 0;
      iVar2 = param_1[400] + iVar4;
      puVar6 = (undefined4 *)(iVar2 + 0x1aa0);
      do {
        uVar3 = uVar3 + 1;
        *puVar6 = 0xffffffff;
        puVar6 = puVar6 + 1;
      } while (uVar3 < 4);
      *(undefined4 *)(iVar2 + 0x1ab0) = 0xffffffff;
      *(undefined1 *)(iVar2 + 0x1ab4) = 0;
      FUN_0008d114(iVar2 + 0x1ab8);
      FUN_0008d2ec(iVar2 + 0x1ae0);
      *(undefined1 *)(iVar2 + 0x1bac) = 0;
      FUN_0008d2ec(iVar2 + 0x1c00);
      FUN_0008d2ec(iVar2 + 0x1d20);
      *(undefined1 *)(iVar2 + 0x1ccc) = 0;
      *(undefined1 *)(iVar2 + 0x1dec) = 0;
      FUN_0008d0e4(iVar2 + 0x1be8,DAT_003415a8 + 4);
      FUN_0008d0cc(iVar2 + 0x1bf8,DAT_003415a8 + 0x18);
      iVar7 = iVar7 + 1;
      iVar4 = iVar4 + 0x458;
    } while (iVar7 < 4);
  }
  FUN_00103540(0x447c8000,param_1);
  FUN_001037c8(param_1,0xffffffff);
  FUN_0001dfe8(DAT_002cfc8c,0x2000);
  FUN_0001e23c(DAT_002cfc8c,0x2000,1);
  if ((int *)param_1[0x16] != (int *)0x0) {
    (**(code **)(*(int *)param_1[0x16] + 0x30))();
  }
  *(undefined1 *)(param_1 + 0x15) = 1;
  *(undefined1 *)((int)param_1 + 0x55) = 0;
  FUN_00103628(param_1,0);
  (**(code **)(*param_1 + 0x10))(param_1);
  FUN_001037c8(param_1,0x10);
  iVar4 = *(int *)(param_1[400] + 0x80);
  if (iVar4 == 0) {
    *(undefined1 *)(param_1 + 0x617) = 1;
    *(undefined1 *)((int)param_1 + 0x185d) = 1;
    *(undefined1 *)((int)param_1 + 0x185e) = 1;
    *(undefined1 *)((int)param_1 + 0x185f) = 1;
  }
  else if (iVar4 == 1) {
    *(undefined1 *)(param_1 + 0x617) = 1;
    *(undefined1 *)((int)param_1 + 0x185d) = 1;
    *(undefined1 *)((int)param_1 + 0x185e) = 1;
    *(undefined1 *)((int)param_1 + 0x185f) = 0;
  }
  else if ((iVar4 == 2) || (iVar4 == 3)) {
    FUN_00262888(DAT_002fde20);
  }
  FUN_001b3ce8(0x34179c,4);
  (**(code **)(*(int *)param_1[0x194] + 0xc))((int *)param_1[0x194],0);
  (**(code **)(*(int *)param_1[0x195] + 0xc))((int *)param_1[0x195],1);
  (**(code **)(*(int *)param_1[0x196] + 0xc))((int *)param_1[0x196],1);
  (**(code **)(*(int *)param_1[0x1a0] + 0xc))((int *)param_1[0x1a0],1);
  (**(code **)(*(int *)param_1[0x197] + 0xc))((int *)param_1[0x197],1);
  (**(code **)(*(int *)param_1[0x16] + 0xc))((int *)param_1[0x16],0);
  (**(code **)(*(int *)param_1[0x16] + 0x30))();
  (**(code **)(*(int *)param_1[0x1a1] + 0xc))((int *)param_1[0x1a1],1);
  FUN_000ffb3c(param_1[0x1a3],0);
  FUN_000ffb3c(param_1[0x1a4],0);
  FUN_000ffb3c(param_1[0x1a5],1);
  FUN_000ffb3c(param_1[0x1a6],1);
  (**(code **)(*(int *)param_1[0x1a2] + 0xc))((int *)param_1[0x1a2],0);
  iVar4 = param_1[0x1a2];
  *(int *)(iVar4 + 0xf8) = param_1[400] + 0x18;
  *(undefined4 *)(iVar4 + 0x138) = 1;
  FUN_0010d4a8();
  FUN_002628b4(param_1,0);
  iVar4 = (int)(FUN_0018c9f4(0x11));
  if (*(int *)(iVar4 + 4) == 0) {
    puVar5 = &DAT_002c0e20;
  }
  else if (*(int *)(*(int *)(iVar4 + 8) + 8) < 0x11) {
    puVar5 = &DAT_002c0e1c;
  }
  else if (*(int *)(*(int *)(iVar4 + 0xc) + 0xc4) < 0xd) {
    puVar5 = &DAT_002c0e18;
  }
  else {
    puVar5 = *(undefined **)(*(int *)(*(int *)(iVar4 + 0xc) + 0xc0) + 0x30);
  }
  FUN_00114168(DAT_003415ac,2,puVar5,0,0);
  param_1[0x619] = 0;
  return;
}
// near miss from lane fm11 (unreviewed)
