/* HSTMATCH module=EBOOT.BIN start=0x0015df28 end=0x0015e268 symbol=FUN_0015df28 lang=c99 rodata=0x002de6d4 */
typedef unsigned int undefined4;
typedef unsigned long long undefined8;
typedef unsigned long long ulonglong;
typedef int code();
#define ABS(x) ((x) < 0 ? -(x) : (x))

extern undefined4 DAT_002de6d4[];
extern undefined4 DAT_002de738;
extern undefined4 DAT_002de73c;
extern undefined4 DAT_002de740;
extern undefined4 DAT_002de744;

extern undefined8 FUN_00022178();
extern undefined8 FUN_0000c07c();
extern undefined8 FUN_00021ac0();
extern int FUN_00022254();
extern void FUN_000ffb3c();
extern float FUN_0000bf34(float);
extern void FUN_0015a304();

void FUN_0015df28(int *param_1)
{
  short sVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  undefined4 *puVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  float fVar9;
  undefined8 uVar10;
  undefined8 uVar11;
  undefined4 auStack_10[4];

  if ((char)param_1[1] != '\0') {
    iVar8 = 0;
    iVar7 = 0;
    puVar5 = DAT_002de6d4;
    piVar6 = param_1;
    do {
      uVar10 = FUN_00022178(iVar7);
      uVar10 = FUN_0000c07c(0, 0x40240000, (int)uVar10, (int)((ulonglong)uVar10 >> 0x20));
      uVar11 = FUN_00022178(*param_1 + 1);
      uVar10 = FUN_00021ac0((int)uVar11, (int)((ulonglong)uVar11 >> 0x20), (int)uVar10,
                            (int)((ulonglong)uVar10 >> 0x20));
      iVar2 = FUN_00022254((int)uVar10, (int)((ulonglong)uVar10 >> 0x20));
      if (iVar2 / 10 + (iVar2 >> 0x1f) == iVar2 >> 0x1f) {
        if (iVar2 % 10 != 0) {
          iVar8 = piVar6[10];
          goto LAB_0015e00c;
        }
        FUN_000ffb3c(piVar6[10], 1);
      }
      else {
        iVar8 = piVar6[10];
LAB_0015e00c:
        FUN_000ffb3c(iVar8, 0);
        iVar8 = iVar7 + 1;
        iVar3 = piVar6[10];
        iVar2 = iVar2 % 10 + puVar5[2];
        *(int *)(iVar3 + 0x24) = iVar2;
        *(int *)(iVar3 + 0x28) = iVar2;
      }
      iVar7 = iVar7 + 1;
      piVar6 = piVar6 + 1;
      puVar5 = puVar5 + 3;
    } while (iVar7 < 3);
    auStack_10[0] = DAT_002de738;
    auStack_10[1] = DAT_002de73c;
    auStack_10[2] = DAT_002de740;
    auStack_10[3] = DAT_002de744;
    iVar7 = param_1[10];
    puVar5 = auStack_10 + iVar8;
    sVar1 = *(short *)(iVar7 + 4);
    sVar4 = (short)param_1[2] - (short)*puVar5;
    *(short *)(iVar7 + 4) = sVar4;
    *(short *)(iVar7 + 8) = *(short *)(iVar7 + 8) + (sVar4 - sVar1);
    iVar7 = param_1[0xb];
    auStack_10[1] = DAT_002de73c;
    auStack_10[2] = DAT_002de740;
    auStack_10[3] = DAT_002de744;
    sVar1 = *(short *)(iVar7 + 4);
    sVar4 = (short)param_1[3] - (short)*puVar5;
    *(short *)(iVar7 + 4) = sVar4;
    *(short *)(iVar7 + 8) = *(short *)(iVar7 + 8) + (sVar4 - sVar1);
    auStack_10[1] = DAT_002de73c;
    auStack_10[2] = DAT_002de740;
    auStack_10[3] = DAT_002de744;
    iVar7 = param_1[0xc];
    sVar4 = (short)param_1[4] - (short)*puVar5;
    sVar1 = *(short *)(iVar7 + 4);
    *(short *)(iVar7 + 4) = sVar4;
    *(short *)(iVar7 + 8) = *(short *)(iVar7 + 8) + (sVar4 - sVar1);
    fVar9 = (float)FUN_0000bf34((float)param_1[5] * 0.2f);
    iVar7 = param_1[0xe];
    sVar1 = *(short *)(iVar7 + 4);
    sVar4 = (short)(int)((float)param_1[6] - ABS(fVar9) * 6.0f);
    *(short *)(iVar7 + 4) = sVar4;
    *(short *)(iVar7 + 8) = *(short *)(iVar7 + 8) + (sVar4 - sVar1);
    iVar7 = param_1[0xd];
    sVar1 = *(short *)(iVar7 + 4);
    sVar4 = (short)(int)((float)param_1[7] + ABS(fVar9) * 6.0f);
    *(short *)(iVar7 + 4) = sVar4;
    *(short *)(iVar7 + 8) = *(short *)(iVar7 + 8) + (sVar4 - sVar1);
    param_1[5] = param_1[5] + 1;
    FUN_000ffb3c(param_1[0xe], *(char *)((int)param_1 + 5) == '\0');
    FUN_000ffb3c(param_1[0xd], *(char *)((int)param_1 + 5) == '\0');
    FUN_0015a304(param_1[8]);
    (**(code **)(*(int *)param_1[0x10] + 0x14))();
  }
  return;
}
// near miss from lane fm10 (unreviewed)
