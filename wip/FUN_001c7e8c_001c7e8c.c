/* HSTMATCH module=EBOOT.BIN start=0x001c7e8c end=0x001c816c symbol=FUN_001c7e8c lang=c99 */
typedef unsigned int undefined4;
typedef unsigned int uint;
typedef int code();

extern undefined4 DAT_0034a118;

extern void FUN_000678a0();
extern void FUN_001b9014();
extern void FUN_002afd2c();
extern void FUN_001fd110();
extern void FUN_000009e4();
extern void FUN_001ce7b0();
extern void FUN_001ce598();
extern void FUN_00127788();
extern void FUN_00289e84();
extern void FUN_001b8fa0();

void FUN_001c7e8c(int param_1, int param_2)
{
  int v1v, v0v, lim;
  float f4[4]; int keep;
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18[3];
  int local_c;
  int local_4;

  if (*(int *)(param_1 + 0x164) != 0) {
    FUN_000678a0();
  }
  FUN_001b9014(*(undefined4 *)(param_1 + 0x160));
  FUN_002afd2c();
  FUN_001fd110();
  *(undefined4 *)(*(int *)(param_1 + 0x15c) + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x74) = 0;
  *(undefined4 *)(param_1 + 0x8c) = 0;
  iVar2 = *(int *)(param_1 + 100);
  iVar1 = iVar2 + *(int *)(param_1 + 0x68) * 4;
  local_c = iVar2;
  local_4 = iVar1;
  for (; iVar1 != iVar2; iVar1 = iVar1 + -4) {
    FUN_000009e4(*(undefined4 *)(iVar1 + -4));
  }
  *(undefined4 *)(param_1 + 0x68) = 0;
  local_18[0] = 0;
  uVar3 = *(uint *)(param_1 + 0x68);
  f4[0] = *(float *)(param_1 + 0x64);
  f4[1] = *(float *)(param_1 + 0x68);
  f4[2] = f4[1];
  f4[3] = f4[0];
  keep = (*(int *)&f4[3] ^ *(int *)&f4[2]) == 0 ? 1 : 0;
  if (uVar3 < 0x28 && keep) {
    FUN_001ce7b0(param_1 + 100, 0x28 - uVar3, local_18, 0);
  }
  else if (0x28 < uVar3) {
    FUN_001ce598((char *)param_1 + 124, 64 - *(int *)(param_1 + 0x80), (char *)local_18, (char)0);
    *(int *)(param_1 + 0x80) = 64;
    FUN_001ce598((char *)param_1 + 76, 40 - *(int *)(param_1 + 0x50), (char *)local_18, (char)0);
    *(int *)(param_1 + 0x50) = 40;
    *(int *)(param_1 + 0x80) = 0;
    *(int *)(param_1 + 0x68) = 40;
    *(int *)(param_1 + 0x50) = 0;
    FUN_001ce7b0((char *)param_1 + 80, 40 - *(int *)(param_1 + 0x50), (char *)local_18, (char)0);
    *(undefined4 *)(param_1 + 0x68) = 0x28;
  }
  *(undefined4 *)(param_1 + 0x50) = 0;
  local_1c = 0;
  uVar3 = *(uint *)(param_1 + 0x50);
  if (uVar3 < 0x28) {
    FUN_001ce7b0((char *)param_1 + 100, 40 - (int)uVar3, (char *)local_18, (char)0);
    FUN_001ce598(param_1 + 0x4c, 0x28 - uVar3, &local_1c, 0);
  }
  else if (0x28 < uVar3) {
    *(undefined4 *)(param_1 + 0x50) = 0x28;
  }
  *(undefined4 *)(param_1 + 0x80) = 0;
  local_20 = 0;
  uVar3 = *(uint *)(param_1 + 0x80);
  if (uVar3 < 0x40) {
    v1v = *(int *)(param_1 + 0x40);
    v0v = *(int *)(param_1 + 0x44);
    lim = v1v + v0v * 4;
    lim = (v1v == lim) ^ 1;
    if ((unsigned)lim < 1) {
      *(int *)(param_1 + 0x6c) = lim;
    }
    FUN_001ce598(param_1 + 0x7c, 0x40 - uVar3, &local_20, 0);
    iVar1 = *(int *)(param_1 + 0x44);
  }
  else {
    if (0x40 < uVar3) {
      *(undefined4 *)(param_1 + 0x80) = 0x40;
    }
    iVar1 = *(int *)(param_1 + 0x44);
  }
  iVar1 = *(int *)(param_1 + 0x40) + iVar1 * 4;
  if (iVar1 != *(int *)(param_1 + 0x40)) {
    piVar4 = *(int **)(iVar1 + -4);
    while (1) {
      if (piVar4 == (int *)0x0) {
        iVar2 = *(int *)(param_1 + 0x40);
      }
      else {
        (**(code **)(*piVar4 + 8))(piVar4, 1);
        iVar2 = *(int *)(param_1 + 0x40);
      }
      if (iVar1 + -4 == iVar2) break;
      piVar4 = *(int **)(iVar1 + -8);
      iVar1 = iVar1 + -4;
    }
  }
  *(undefined4 *)(param_1 + 0x44) = 0;
  DAT_0034a118 = 0;
  FUN_00127788();
  if (param_2 != 0) {
    FUN_00289e84(param_1 + 0x180);
    FUN_001b8fa0(*(undefined4 *)(param_1 + 0x160));
  }
  return;
}
// near miss from lane fm10 (unreviewed)
