/* HSTMATCH module=EBOOT.BIN start=0x00210f9c end=0x002111cc symbol=FUN_00210f9c lang=c99 */
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

extern float DAT_002efa88;
extern float DAT_002efa8c;
extern float DAT_002efa90;
extern undefined * DAT_00338b44;
extern uint FUN_0001342c();
extern bool FUN_000a8494();
extern int FUN_00215a20();
extern int FUN_00215a58();

float FUN_00210f9c(float param_1,int param_2)
{
  short sVar1;
  float fVar2;
  int iVar3;
  uint uVar4;
  float fVar5;
  float fVar6;
  
  if (*(char *)(DAT_00338b44 + 0x45) == '\0') {
    fVar2 = 5.4863997f;
  }
  else {
    fVar2 = 4.1148f;
  }
  if (param_1 != 0.0f) {
    iVar3 = FUN_00215a58(param_2);
    fVar5 = *(float *)(iVar3 + 0xa4);
    iVar3 = FUN_00215a20(param_2);
    fVar5 = fVar5 + *(float *)(iVar3 + 0xa4);
    fVar6 = DAT_002efa88;
    if (DAT_002efa88 <= fVar5) {
      fVar6 = fVar5;
    }
    uVar4 = FUN_0001342c();
    if ((float)(int)(uVar4 & 0xfffff800) * 4.656613e-10f < fVar6 * 0.01f) {
      return fVar2 * param_1;
    }
  }
  iVar3 = FUN_000a8494(param_2,param_2 + 0x580);
  if (iVar3 == 0) {
    iVar3 = FUN_00215a58(param_2);
    sVar1 = *(short *)(iVar3 + 0xa8);
    iVar3 = FUN_00215a20(param_2);
    fVar5 = (float)((int)sVar1 + (int)*(short *)(iVar3 + 0xa8));
    fVar6 = DAT_002efa90;
    if (DAT_002efa90 <= fVar5) {
      fVar6 = fVar5;
    }
  }
  else {
    iVar3 = FUN_00215a58(param_2);
    sVar1 = *(short *)(iVar3 + 0xaa);
    iVar3 = FUN_00215a20(param_2);
    fVar5 = (float)((int)sVar1 + (int)*(short *)(iVar3 + 0xaa));
    fVar6 = DAT_002efa8c;
    if (DAT_002efa8c <= fVar5) {
      fVar6 = fVar5;
    }
  }
  fVar2 = (fVar2 - fVar6 * 0.01f) * 0.6666667f;
  uVar4 = FUN_0001342c();
  return param_1 * fVar2 +
         -fVar2 * 0.5f +
         (fVar2 * 0.5f - -fVar2 * 0.5f) * 4.656613e-10f * (float)(int)(uVar4 & 0xfffff800);
}
// near miss from lane fm9 (unreviewed)
