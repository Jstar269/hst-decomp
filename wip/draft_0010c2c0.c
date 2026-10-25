/* HSTMATCH module=EBOOT.BIN start=0x0010c2c0 end=0x0010c69c symbol=FUN_0010c2c0 lang=c99 */
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

extern int DAT_002d9218;
extern undefined4 DAT_003417a4;
extern void FUN_000ffb3c();
extern void FUN_000ffca4();
extern void FUN_001087d0();
extern void FUN_0010b614();
extern void FUN_0010b76c();

void FUN_0010c2c0(int *param_1)
{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  
  param_1[2] = 0;
  param_1[0x1a] = 0;
  param_1[2] = 3;
  piVar8 = *(int **)(*(int *)(*param_1 + 0x10) + param_1[3] * 4);
  piVar7 = *(int **)(*(int *)(*param_1 + 0x10) + (param_1[3] + 1) * 4);
  FUN_000ffca4((int)piVar8);
  FUN_000ffca4((int)piVar7);
  FUN_000ffb3c((int)piVar8,0);
  FUN_000ffb3c((int)piVar7,0);
  *piVar8 = -0x7fdfca90;
  *piVar7 = -0x7f80bfe0;
  iVar6 = (int)(short)((short)piVar8[2] - (short)piVar8[1]);
  iVar2 = iVar6;
  if (iVar6 < 0) {
    iVar2 = iVar6 + 1;
  }
  sVar1 = -0x32 - (short)(iVar2 >> 1);
  iVar5 = (int)(short)((short)piVar7[2] - (short)piVar7[1]);
  iVar2 = iVar5;
  if (iVar5 < 0) {
    iVar2 = iVar5 + 1;
  }
  sVar4 = 0x32 - (short)(iVar2 >> 1);
  iVar2 = piVar8[1];
  *(short *)(piVar8 + 1) = sVar1;
  *(short *)(piVar8 + 2) = (short)piVar8[2] + (sVar1 - (short)iVar2);
  iVar2 = piVar7[1];
  *(short *)(piVar7 + 1) = sVar4;
  *(short *)(piVar7 + 2) = (short)piVar7[2] + (sVar4 - (short)iVar2);
  param_1[4] = *piVar8;
  *(short *)(param_1 + 5) = (short)piVar8[1];
  *(undefined2 *)((int)param_1 + 0x16) = *(undefined2 *)((int)piVar8 + 6);
  *(short *)(param_1 + 6) = (short)piVar8[2];
  *(undefined2 *)((int)param_1 + 0x1a) = *(undefined2 *)((int)piVar8 + 10);
  *(short *)(param_1 + 7) = (short)piVar8[3];
  *(undefined2 *)((int)param_1 + 0x1e) = *(undefined2 *)((int)piVar8 + 0xe);
  param_1[8] = piVar8[4];
  param_1[9] = piVar8[5];
  param_1[10] = piVar8[6];
  param_1[0xb] = piVar8[7];
  param_1[0xc] = piVar8[8];
  param_1[0xd] = piVar8[9];
  param_1[0xe] = piVar8[10];
  param_1[0xf] = *piVar7;
  *(short *)(param_1 + 0x10) = (short)piVar7[1];
  *(undefined2 *)((int)param_1 + 0x42) = *(undefined2 *)((int)piVar7 + 6);
  *(short *)(param_1 + 0x11) = (short)piVar7[2];
  *(undefined2 *)((int)param_1 + 0x46) = *(undefined2 *)((int)piVar7 + 10);
  *(short *)(param_1 + 0x12) = (short)piVar7[3];
  *(undefined2 *)((int)param_1 + 0x4a) = *(undefined2 *)((int)piVar7 + 0xe);
  param_1[0x13] = piVar7[4];
  param_1[0x14] = piVar7[5];
  param_1[0x15] = piVar7[6];
  param_1[0x16] = piVar7[7];
  param_1[0x17] = piVar7[8];
  param_1[0x18] = piVar7[9];
  param_1[0x19] = piVar7[10];
  *(undefined4 *)(*param_1 + 0xd4) = 2;
  iVar2 = *param_1;
  *(undefined4 *)(iVar2 + 0xd8) = 1;
  *(undefined1 *)(iVar2 + 0x114) = 1;
  iVar2 = *param_1;
  *(undefined4 *)(iVar2 + 0x110) = 0;
  *(undefined4 *)(iVar2 + 0xdc) = 0;
  *(undefined2 *)(iVar2 + 0xec) = 0;
  *(undefined2 *)(iVar2 + 0xee) = 0;
  *(undefined4 *)(iVar2 + 0xd0) = 0;
  FUN_001087d0(iVar2 + 0x120,*(int *)(iVar2 + 0x124));
  FUN_0010b76c(*param_1,(sVar1 - (short)(iVar6 / 4)) + 5,4,0,0,3);
  sVar1 = (short)(iVar5 >> 2);
  if (DAT_003417a4 == 9) {
    if (iVar5 < 0) {
      sVar1 = (short)(iVar5 + 3 >> 2);
    }
    FUN_0010b76c(*param_1,(sVar4 - sVar1) + -8,4,0,0,3);
  }
  else {
    if (iVar5 < 0) {
      sVar1 = (short)(iVar5 + 3 >> 2);
    }
    FUN_0010b76c(*param_1,(sVar4 - sVar1) + 5,4,0,0,3);
  }
  iVar6 = *param_1;
  iVar2 = *(int *)(iVar6 + 0xe4) - *(int *)(iVar6 + 0xe0);
  if (DAT_002d9218 < 2) {
    if (0 < iVar2) {
      iVar2 = 1;
    }
    iVar5 = *(int *)(iVar6 + 0xdc);
  }
  else {
    iVar5 = *(int *)(iVar6 + 0xdc);
    iVar2 = DAT_002d9218;
  }
  if (iVar5 == iVar2) {
    *(int *)(iVar6 + 0xdc) = iVar2;
  }
  else {
    if (*(short *)(*(int *)(iVar6 + 0x120) + iVar5 * 0xc) ==
        *(short *)(*(int *)(iVar6 + 0x120) + iVar2 * 0xc)) {
      uVar3 = 0;
    }
    else {
      uVar3 = 3;
    }
    *(undefined4 *)(iVar6 + 0xd0) = uVar3;
    *(undefined1 *)(iVar6 + 0xea) = 1;
    *(int *)(iVar6 + 0xdc) = iVar2;
  }
  *(undefined1 *)(iVar6 + 0x114) = 1;
  FUN_0010b614(*param_1);
  return;
}
// near miss from lane fm11 (unreviewed)
