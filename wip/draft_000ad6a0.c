/* HSTMATCH module=EBOOT.BIN start=0x000ad6a0 end=0x000ada80 symbol=FUN_000ad6a0 lang=c99 */
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

extern float DAT_002d46f8;
extern float DAT_002d46fc;
extern float DAT_002d4700;
extern float DAT_002d4704;
extern float DAT_002d4708;
extern float DAT_003411fc;
extern float DAT_00341200;
extern undefined4 DAT_0034126c;
extern undefined4 DAT_00341270;
extern undefined4 DAT_00341274;
extern float DAT_00341278;
extern float DAT_0034127c;
extern float DAT_00341280;
extern float DAT_003414e8;
extern float DAT_003414ec;
extern float DAT_003414f0;
extern int FUN_000b3c68();
extern float FUN_00163f58();

float FUN_000ad6a0(int param_1,float *param_2,float *param_3,float *param_4,float *param_5, int param_6,int param_7,int param_8)
{
  int iVar1;
  undefined4 uVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  
  fVar6 = 1.0f;
  if (((param_7 == 1) || (param_7 == 2)) || (param_7 == 10)) {
    iVar1 = FUN_000b3c68(param_1);
    *param_2 = -(*(float *)(iVar1 + 0x24) * 0.01f);
    iVar1 = FUN_000b3c68(param_1);
    *param_3 = -(*(float *)(iVar1 + 0x3c) * 0.01f);
  }
  else {
    *param_2 = -0.0f;
    iVar1 = FUN_000b3c68();
    *param_3 = -(*(float *)(iVar1 + 0x24) * 0.01f);
  }
  if (param_7 != 1) {
    fVar3 = DAT_00341200 * 0.01f;
    *param_4 = *param_2 + DAT_003411fc * 0.01f * (*param_3 - *param_2);
    *param_5 = *param_3 + fVar3 * (*param_2 - *param_3);
    goto LAB_000ad934;
  }
  fVar5 = 0.0f;
  uVar2 = FUN_000b3c68(param_1);
  fVar3 = (float)FUN_00163f58(uVar2,*(undefined4 *)(param_1 + 0x154));
  if (param_6 == 2) {
    fVar5 = (DAT_00341274 + DAT_00341280 * fVar3) * 0.01f;
    fVar6 = DAT_003414f0 * 0.01f;
LAB_000ad870:
    fVar3 = *param_2;
  }
  else {
    if (param_6 == 1) {
      fVar5 = (DAT_00341270 + DAT_0034127c * fVar3) * 0.01f;
      fVar6 = DAT_003414ec * 0.01f;
      goto LAB_000ad870;
    }
    if (param_6 == 0) {
      fVar5 = (DAT_0034126c + DAT_00341278 * fVar3) * 0.01f;
      fVar6 = DAT_003414e8 * 0.01f;
      goto LAB_000ad870;
    }
    fVar3 = *param_2;
  }
  fVar3 = fVar3 + DAT_002d46f8 * (*param_3 - fVar3);
  *param_4 = fVar3 + fVar5 * 0.5f;
  *param_5 = fVar3 - fVar5 * 0.5f;
  fVar3 = *param_2;
  if (*param_4 <= *param_2) {
    fVar3 = *param_4;
  }
  *param_4 = fVar3;
  fVar3 = *param_3;
  if (*param_3 <= *param_5) {
    fVar3 = *param_5;
  }
  *param_5 = fVar3;
LAB_000ad934:
  fVar5 = *(float *)(param_8 + 4);
  fVar3 = *param_4;
  if (fVar5 <= fVar3) {
    if (*param_5 <= fVar5) {
      return 0.0f;
    }
    fVar4 = *param_5;
  }
  else {
    fVar4 = *param_5;
  }
  if (fVar5 <= fVar4) {
    fVar3 = (fVar5 - fVar4) / (fVar6 * (*param_3 - fVar4));
    fVar6 = DAT_002d46fc;
    if ((DAT_002d46fc <= fVar3) && (fVar6 = DAT_002d4700, fVar3 <= DAT_002d4700)) {
      fVar6 = fVar3;
    }
  }
  else {
    fVar3 = (fVar5 - fVar3) / (fVar6 * (*param_2 - fVar3));
    fVar6 = DAT_002d4704;
    if ((DAT_002d4704 <= fVar3) && (fVar6 = DAT_002d4708, fVar3 <= DAT_002d4708)) {
      fVar6 = fVar3;
    }
    fVar6 = fVar6 * -1.0f;
  }
  return fVar6;
}
// near miss from lane fm11 (unreviewed)
