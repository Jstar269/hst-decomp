/* HSTMATCH module=EBOOT.BIN start=0x000a902c end=0x000a938c symbol=FUN_000a902c lang=c99 rodata=0x002d46a4 */
typedef unsigned int undefined4;
typedef unsigned char bool;
#define ABS(x) ((x) < 0 ? -(x) : (x))

extern float DAT_002d46a4;
extern float DAT_002d46a8;
extern float DAT_002d46ac;
extern float DAT_0034129c;
extern float DAT_00341294;
extern float DAT_00341284;
extern float DAT_00341288;
extern undefined4 DAT_00341120;

extern void FUN_00022434();
extern int FUN_000b3c68();
extern float FUN_001621c0();
extern float FUN_00164474();
extern float FUN_0016442c();

undefined4 FUN_000a902c(int param_1, undefined4 param_2, undefined4 param_3, char param_4)
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float local_20;
  float local_1c;
  float local_18;
  undefined4 local_14;
  float local_10;
  float local_c;
  float local_8;
  undefined4 local_4;

  FUN_00022434(&local_20);
  local_c = local_1c;
  local_8 = local_18;
  local_4 = local_14;
  local_10 = local_20;
  if ((bool)param_4 == (*(int *)(param_1 + 0x150) == 0)) {
    if (local_20 <= DAT_002d46a4) {
      local_10 = DAT_002d46a4;
    }
  }
  else if (DAT_002d46a8 <= local_20) {
    local_10 = DAT_002d46a8;
  }
  fVar5 = local_10;
  iVar2 = FUN_000b3c68(param_1);
  if (ABS(fVar5) < *(float *)(iVar2 + 0x2c) * 0.01f) {
    fVar7 = local_18 - DAT_0034129c * 0.01f;
    fVar6 = 0.0f;
    fVar8 = ABS(fVar7);
    fVar4 = FUN_001621c0(&DAT_00341120, 0);
    if (fVar4 * 0.01f < fVar8) {
      if (fVar7 < 0.0f) {
        iVar2 = -1;
      }
      else {
        iVar2 = 1;
      }
      fVar6 = FUN_001621c0(&DAT_00341120, 0);
      fVar7 = fVar7 - (float)iVar2 * fVar6 * 0.01f;
      if (0.0f < fVar7) {
        fVar6 = DAT_00341294 * 0.01f * (float)DAT_00341284;
      }
      else {
        fVar6 = DAT_00341294 * 0.01f * (float)DAT_00341288;
      }
      fVar7 = fVar7 / fVar6;
      fVar6 = DAT_002d46ac;
      if (fVar7 <= DAT_002d46ac) {
        fVar6 = fVar7;
      }
    }
    uVar3 = FUN_000b3c68(param_1);
    fVar7 = FUN_00164474(uVar3, *(undefined4 *)(param_1 + 0x440));
    fVar7 = fVar7 * 0.01f;
    uVar3 = FUN_000b3c68(param_1);
    fVar4 = FUN_0016442c(uVar3, *(undefined4 *)(param_1 + 0x440));
    iVar2 = FUN_000b3c68(param_1);
    if ((1.0f - (fVar4 * 0.01f + fVar6 * (fVar7 - fVar4 * 0.01f))) *
            *(float *)(iVar2 + 0x2c) * 0.01f <= ABS(fVar5)) {
      bVar1 = 1;
    }
    else {
      bVar1 = 0;
    }
  }
  else {
    bVar1 = 0;
  }
  if (bVar1) {
    iVar2 = FUN_000b3c68(param_1);
    if (-(*(float *)(iVar2 + 0x24) * 0.01f) < local_1c) {
      if (local_1c < 0.0f) {
        bVar1 = 1;
      }
      else {
        bVar1 = 0;
      }
    }
    else {
      bVar1 = 0;
    }
    if (bVar1) {
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
    }
  }
  else {
    uVar3 = 0;
  }
  return uVar3;
}
// near miss from lane fm10 (unreviewed)
