/* HSTMATCH module=EBOOT.BIN start=0x000f1c7c end=0x000f1fdc symbol=FUN_000f1c7c lang=c99 rodata=0x002d7834 */
typedef unsigned int undefined4;
typedef int code();
#define ABS(x) ((x) < 0 ? -(x) : (x))

extern float DAT_002d7834;
extern float DAT_002d7838;

extern void FUN_0010e5b8();
extern void FUN_00103480();
extern void FUN_00103128();

void FUN_000f1c7c(int param_1)
{
  char cVar1;
  float fVar2;
  float fVar3;
  int *piVar;

  if (*(char *)(param_1 + 0x78) == '\0') {
    if (*(float *)(param_1 + 0x7c) <= 0.0f) {
      cVar1 = *(char *)(param_1 + 0x79);
      goto LAB_000f1f48;
    }
    fVar2 = *(float *)(param_1 + 0x94);
    if (fVar2 < *(float *)(param_1 + 0x90)) {
      fVar2 = fVar2 + DAT_002d7834;
      if (fVar2 < (float)DAT_002d7838) {
        fVar3 = (float)DAT_002d7838;
      }
      else {
        fVar3 = *(float *)(param_1 + 0x90);
        if (fVar2 <= fVar3) {
          fVar3 = fVar2;
        }
      }
      *(float *)(param_1 + 0x94) = fVar3;
      if (2.0f < fVar3) {
        piVar = *(int **)(param_1 + 0x68);
        (**(code **)(*piVar + 0xc))(piVar, 0);
        FUN_0010e5b8(*(undefined4 *)(param_1 + 0x68), 0, 0, (int)fVar3, 7, 0, 0, 3);
        fVar2 = *(float *)(param_1 + 0x88);
      }
      else {
        piVar = *(int **)(param_1 + 0x68);
        (**(code **)(*piVar + 0xc))(piVar, 1);
        fVar2 = *(float *)(param_1 + 0x88);
      }
      piVar = *(int **)(param_1 + 0x68);
      if (fVar2 <= fVar3) {
        (**(code **)(*piVar + 0x18))(piVar, 0x80673376);
      }
      else if (*(float *)(param_1 + 0x84) <= fVar3) {
        (**(code **)(*piVar + 0x18))(piVar, 0x8000427f);
      }
      else {
        (**(code **)(*piVar + 0x18))(piVar, 0x801a1c75);
      }
    }
    else if (*(float *)(param_1 + 0x90) < fVar2) {
      fVar2 = fVar2 - DAT_002d7834;
      fVar3 = *(float *)(param_1 + 0x90);
      if ((*(float *)(param_1 + 0x90) <= fVar2) &&
          (fVar3 = *(float *)(param_1 + 0x94), fVar2 <= fVar3)) {
        fVar3 = fVar2;
      }
      *(float *)(param_1 + 0x94) = fVar3;
      if (2.0f < fVar3) {
        piVar = *(int **)(param_1 + 0x68);
        (**(code **)(*piVar + 0xc))(piVar, 0);
        FUN_0010e5b8(*(undefined4 *)(param_1 + 0x68), 0, 0, (int)fVar3, 7, 0, 0, 3);
        fVar2 = *(float *)(param_1 + 0x88);
      }
      else {
        piVar = *(int **)(param_1 + 0x68);
        (**(code **)(*piVar + 0xc))(piVar, 1);
        fVar2 = *(float *)(param_1 + 0x88);
      }
      piVar = *(int **)(param_1 + 0x68);
      if (fVar2 <= fVar3) {
        (**(code **)(*piVar + 0x18))(piVar, 0x80673376);
      }
      else if (*(float *)(param_1 + 0x84) <= fVar3) {
        (**(code **)(*piVar + 0x18))(piVar, 0x8000427f);
      }
      else {
        (**(code **)(*piVar + 0x18))(piVar, 0x801a1c75);
      }
    }
  }
  cVar1 = *(char *)(param_1 + 0x79);
LAB_000f1f48:
  fVar2 = *(float *)(param_1 + 0x7c);
  if (cVar1 == '\0') {
    fVar3 = 0.0f;
  }
  else {
    fVar3 = 1.0f;
  }
  if (fVar2 < fVar3) {
    if (0.01f <= ABS(fVar3 - fVar2)) {
      fVar3 = fVar2 + (fVar3 - fVar2) * 0.3f;
    }
    *(float *)(param_1 + 0x7c) = fVar3;
  }
  else {
    *(float *)(param_1 + 0x7c) = fVar3;
  }
  if (fVar2 != *(float *)(param_1 + 0x7c)) {
    *(float *)(*(int *)(param_1 + 0x54) + 0x78) = *(float *)(param_1 + 0x7c);
    FUN_00103480(param_1);
  }
  FUN_00103128(param_1);
  *(int *)(param_1 + 0x74) = *(int *)(param_1 + 0x74) + 1;
  return;
}
// near miss from lane fm10 (unreviewed)
