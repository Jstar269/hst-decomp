/* HSTMATCH module=EBOOT.BIN start=0x00221314 end=0x00221590 symbol=FUN_00221314 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode corrected by hand: typed float globals, preserved the shared input load, and matched the state/limit branch layout; exact match verified; names and types await human review. */
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

extern undefined * DAT_002cfc8c;
extern int DAT_002eff90;
extern int DAT_002eff94;
extern float DAT_002f0d0c;
extern float DAT_002f0d10;
extern undefined DAT_0034179c;
extern float DAT_0034a240;
extern float DAT_0034a244;
extern float FUN_0000bd2c(float param_1);
extern float FUN_000ede98(float param_1,float param_2,float param_3,float param_4);
extern void FUN_000ffb3c(int, int);
extern void FUN_00103128(int);
extern void FUN_00103480(int);
extern void FUN_00103628(int, int);
extern int FUN_001b1c44(int *, int);

void FUN_00221314(int param_1)
{
  int iVar1;
  int iVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float input;
  
  if (*(int *)(param_1 + 0x60) < 0) goto LAB_00221564;
  iVar1 = *(int *)(param_1 + 100);
  fVar5 = *(volatile float *)(iVar1 + 100);
  fVar6 = *(volatile float *)(iVar1 + 0x78);
  input = *(volatile float *)(iVar1 + 0x60);
  if (*(int *)(param_1 + 0x60) < 100) {
    fVar3 = FUN_000ede98(input,0.0f,DAT_002f0d10,0.01f);
    fVar5 = FUN_000ede98(fVar5,0.0f,DAT_002f0d10,0.01f);
    fVar6 = FUN_000ede98(fVar6,1.0f,DAT_002f0d10,0.01f);
  }
  else {
    fVar3 = FUN_000ede98(input,-DAT_0034a240,DAT_002f0d10,0.01f);
    fVar5 = FUN_000ede98(fVar5,-DAT_0034a244,DAT_002f0d10,0.01f);
    fVar6 = FUN_000ede98(fVar6,DAT_002f0d0c,DAT_002f0d10,0.01f);
  }
  iVar2 = 0;
  iVar1 = param_1;
  do {
    fVar4 = FUN_0000bd2c(fVar3);
    *(float *)(*(int *)(iVar1 + 100) + 0x60) = fVar4;
    fVar4 = FUN_0000bd2c(fVar5);
    iVar2 = iVar2 + 1;
    *(float *)(*(int *)(iVar1 + 100) + 100) = fVar4;
    *(float *)(*(int *)(iVar1 + 100) + 0x78) = fVar6;
    iVar1 = iVar1 + 4;
  } while (iVar2 < 5);
  FUN_00103480(param_1);
  if (*(int *)(param_1 + 0x60) >= DAT_002eff90 + 0x14 && *(unsigned char *)(param_1 + 0x9c) != 0) {
    FUN_000ffb3c(*(int *)(param_1 + 0x80),0);
    FUN_000ffb3c(*(int *)(param_1 + 0x84),0);
    if (((int)*(char *)(DAT_002cfc8c + 0x8b) << 0x1c) >> 0x1e == 0) {
      FUN_001b1c44((int *)&DAT_0034179c,3);
      *(undefined1 *)(param_1 + 0x9c) = 0;
      *(undefined4 *)(param_1 + 0x60) = 100;
    }
  } else {
    FUN_000ffb3c(*(int *)(param_1 + 0x80),1);
    FUN_000ffb3c(*(int *)(param_1 + 0x84),1);
    *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + 1;
  }
  if (!(*(int *)(param_1 + 0x60) < DAT_002eff94)) {
    FUN_00103628(param_1, 1);
    *(undefined1 *)(param_1 + 0x58) = 1;
    *(undefined4 *)(param_1 + 0x60) = 0xffffffff;
  }
LAB_00221564:
  FUN_00103128(param_1);
  return;
}
