/* HSTMATCH module=EBOOT.BIN start=0x0022039c end=0x002205e4 symbol=FUN_0022039c lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode corrected by hand: typed float globals, hoisted the shared source float, and matched the color conversion and completion branches; exact match verified; names and types await human review. */
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

extern int DAT_002eff94;
extern float DAT_002f0b4c;
extern float DAT_002f0b50;
extern float DAT_0034a200;
extern float DAT_0034a204;
extern float FUN_0000bd2c(float param_1);
extern float FUN_000ede98(float param_1,float param_2,float param_3,float param_4);
extern void FUN_00103128(int);
extern void FUN_00103480(int);
extern void FUN_00103628(int, int);
extern void FUN_0027fc70(uint *, uint *, int);

void FUN_0022039c(int param_1)
{
  int iVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float input;
  
  if (*(int *)(param_1 + 0x5c) < 0) goto LAB_002205bc;
    iVar1 = *(int *)(param_1 + 0x60);
    fVar4 = *(volatile float *)(iVar1 + 100);
    fVar5 = *(volatile float *)(iVar1 + 0x78);
    input = *(volatile float *)(iVar1 + 0x60);
    if (*(int *)(param_1 + 0x5c) < 100) {
      fVar2 = FUN_000ede98(input,0.0f,DAT_002f0b50,0.01f);
      fVar3 = FUN_000ede98(fVar4,0.0f,DAT_002f0b50,0.01f);
      fVar4 = FUN_000ede98(fVar5,1.0f,DAT_002f0b50,0.01f);
    }
    else {
      fVar2 = FUN_000ede98(input,DAT_0034a200,DAT_002f0b50,0.01f);
      fVar3 = FUN_000ede98(fVar4,DAT_0034a204,DAT_002f0b50,0.01f);
      fVar4 = FUN_000ede98(fVar5,DAT_002f0b4c,DAT_002f0b50,0.01f);
    }
    fVar5 = FUN_0000bd2c(fVar2);
    *(float *)(*(int *)(param_1 + 0x60) + 0x60) = fVar5;
    fVar5 = FUN_0000bd2c(fVar3);
    *(float *)(*(int *)(param_1 + 0x60) + 100) = fVar5;
    *(float *)(*(int *)(param_1 + 0x60) + 0x78) = fVar4;
    FUN_00103480(param_1);
    if (*(int *)(param_1 + 0x5c) < 0x5a) {
      FUN_0027fc70((uint *)(param_1 + 0x70),*(uint **)(param_1 + 0x68),1);
      iVar1 = *(int *)(param_1 + 0x5c);
    }
    else {
      float scaled = fVar4 * 255.0f;
      int component;
      uint *colorp = *(uint **)(param_1 + 0x68);
      if (2.1474836e+09f <= scaled) goto LAB_00220540;
      component = (int)scaled;
      goto LAB_00220554;
LAB_00220540:
      scaled = scaled - 2.1474836e+09f;
      component = (int)scaled | -32768;
LAB_00220554:;
      uint high = (uint)(component & 0xff) << 0x18;
      uint old = *(volatile uint *)colorp;
      *colorp = (old & 0xffffff) | high;
      iVar1 = *(int *)(param_1 + 0x5c);
    }
    if (iVar1 < 99) {
      *(int *)(param_1 + 0x5c) = iVar1 + 1;
    }
    if (!(*(int *)(param_1 + 0x5c) < DAT_002eff94)) {
      FUN_00103628(param_1,1);
      *(undefined1 *)(param_1 + 0x54) = 1;
      *(undefined4 *)(param_1 + 0x5c) = 0xffffffff;
    }
LAB_002205bc:
  FUN_00103128(param_1);
  return;
}
