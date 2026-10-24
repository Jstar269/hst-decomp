/* HSTMATCH module=EBOOT.BIN start=0x000ad2f0 end=0x000ad5f0 symbol=FUN_000ad2f0 lang=c99 */
typedef unsigned int undefined4;

#define ABS(x) ((x) < 0 ? -(x) : (x))

extern float DAT_0034118c;
extern float DAT_00341188;
extern float DAT_00341174;
extern float DAT_0034117c;
extern float DAT_003412a0;
extern float DAT_003412a4;
extern float DAT_003412a8;
extern float DAT_003412ac;
extern float DAT_003412b0;
extern char DAT_00341304;
extern char *DAT_003386b0;
extern char *DAT_00338b44;

extern int FUN_000ad674();
extern int FUN_000b3c68();
extern void FUN_00022450();

void FUN_000ad2f0(float param_1, float param_2, float *param_3, int param_4, undefined4 param_5)
{
  int iVar1;
  float *pfVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float f20;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_c;
  float local_8;
  float local_4;

  local_20 = 0.0f;
  local_1c = 0.0f;
  local_18 = 0.0f;
  local_14 = 0.0f;
  iVar1 = FUN_000ad674(param_4, param_5);
  if (iVar1 == 2) {
    iVar1 = FUN_000b3c68(param_4);
    f20 = *(float *)(iVar1 + 0x20) * 0.01f;
  }
  else if (iVar1 == 1) {
    iVar1 = FUN_000b3c68(param_4);
    f20 = *(float *)(iVar1 + 0x1c) * 0.01f;
  }
  else if (iVar1 == 0) {
    iVar1 = FUN_000b3c68(param_4);
    f20 = *(float *)(iVar1 + 0x18) * 0.01f;
  }
  local_4 = DAT_0034118c * 0.01f;
  if (*(char *)(DAT_00338b44 + 0x45) == '\0') {
    f20 = f20 + DAT_00341188 * 0.01f;
    local_4 = DAT_0034118c * 0.01f + DAT_00341188 * 0.01f;
  }
  local_20 = f20 * param_1;
  local_14 = 1.0f;
  local_1c = -*(float *)(*(int *)(DAT_003386b0 + 0x88) + 0x110);
  fVar4 = *(float *)(param_4 + 0x580);
  fVar5 = DAT_003412a0 * fVar4;
  if (DAT_00341304 != '\0') {
    if (DAT_0034118c == 0.0f) {
      if ((param_1 != 0.0f) && (f20 != 0.0f)) {
        if (0.0f <= param_1 * fVar4) {
          fVar5 = fVar5 * DAT_003412a4;
          if (ABS(local_20 + fVar5) < ABS(fVar4)) {
            fVar5 = fVar4 - local_20;
          }
        }
        else {
          fVar5 = fVar5 * DAT_003412a8;
        }
      }
    }
    else if (param_1 == 0.0f) {
      local_8 = local_20 + fVar5;
      if (0.0f < local_8) {
        if (local_4 < local_8) {
          pfVar2 = &local_4;
        }
        else {
          pfVar2 = &local_8;
        }
        local_8 = *pfVar2;
      }
      else {
        local_c = -local_4;
        if (local_8 < -local_4) {
          pfVar2 = &local_c;
        }
        else {
          pfVar2 = &local_8;
        }
        local_8 = *pfVar2;
      }
      fVar5 = local_8 - local_20;
    }
    else {
      fVar3 = local_4 - f20;
      fVar6 = DAT_003412a4;
      if (param_1 * fVar4 < 0.0f) {
        fVar6 = DAT_003412a8;
      }
      fVar6 = fVar5 * fVar6;
      fVar5 = -fVar3;
      if ((-fVar3 <= fVar6) && (fVar5 = fVar3, fVar6 <= fVar3)) {
        fVar5 = fVar6;
      }
    }
  }
  local_20 = local_20 + fVar5;
  local_18 = DAT_00341174 * 0.01f + DAT_0034117c * 0.01f * param_2 +
             DAT_003412ac * (*(float *)(param_4 + 0x588) + DAT_003412b0 * 0.01f);
  FUN_00022450(&local_20, &local_20, param_4 + 0x5a0);
  *param_3 = local_20;
  param_3[1] = local_1c;
  param_3[2] = local_18;
  param_3[3] = local_14;
  return;
}

// NEAR MISS 0x000ad2f0 (coverage pass, 1 compile): 214/192 words (+22), first diff at +0x0.
// Over-expansion suspects: the uninitialised f20 local (retail keeps it in a saved fp reg
// across the FUN_000b3c68 calls - try making it a plain float computed once with a single
// switch on iVar1 instead of the if/else ladder), and the repeated *0.01f scaling which
// retail may fold into one constant multiply per site.
// near miss from lane fm10 (unreviewed)
