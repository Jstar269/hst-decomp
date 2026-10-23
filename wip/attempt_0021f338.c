/* HSTMATCH module=EBOOT.BIN start=0x0021f338 end=0x0021f59c symbol=FUN_0021f338 lang=c99 */
#pragma opt_strength_reduction on
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
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
extern float DAT_002f091c;
extern float DAT_0034a1c0;
extern float DAT_0034a1c4;
extern float DAT_0034a1d0;
extern undefined DAT_0034179c;
extern float FUN_0000bd2c(float param_1);
extern float FUN_000ede98(float param_1,float param_2,float param_3,float param_4);
extern void FUN_000ffb3c(int, int);
extern void FUN_00103128(int);
extern void FUN_00103480(int);
extern void FUN_00103628(int, int);
extern int FUN_001b1c44(int *, int);
extern int FUN_001b1f7c(void *);

typedef struct StatusOverlay {
  char pad[0x60];
  volatile int state;
} StatusOverlay;

static inline int statusIsNegative(int value)
{
  return value < 0;
}

void FUN_0021f338(register char *param_1)
{
  long status;
  StatusOverlay *stateObject = (StatusOverlay *)param_1;
  int iVar1;
  int iVar2;
  float uVar3;
  float uVar4;
  float uVar5;
  float input;
  
  iVar2 = *(int *)(param_1 + 0x60);
  if (iVar2 < 0) goto LAB_0021f378;
  if (FUN_001b1f7c(&DAT_0034179c) == 0) {
    *(int *)(param_1 + 0x60) = -1;
  }
LAB_0021f378:
  iVar1 = *(int *)(param_1 + 0x5c);
  if (iVar1 < 0) goto LAB_0021f578;
  iVar2 = *(int *)(param_1 + 100);
  uVar4 = *(volatile float *)(iVar2 + 100);
  uVar5 = *(volatile float *)(iVar2 + 0x78);
  input = *(volatile float *)(iVar2 + 0x60);
  if (iVar1 < 100) {
    uVar3 = FUN_000ede98(input,0.0f,DAT_002f091c,0.01f);
    uVar4 = FUN_000ede98(uVar4,0.0f,DAT_002f091c,0.01f);
    uVar5 = FUN_000ede98(uVar5,1.0f,DAT_002f091c,0.01f);
  }
  else {
    uVar3 = FUN_000ede98(input,-DAT_0034a1c0,DAT_002f091c,0.01f);
    uVar4 = FUN_000ede98(uVar4,-DAT_0034a1c4,DAT_002f091c,0.01f);
    uVar5 = FUN_000ede98(uVar5,DAT_0034a1d0,DAT_002f091c,0.01f);
  }
  uVar3 = FUN_0000bd2c(uVar3);
  *(float *)(*(int *)(param_1 + 100) + 0x60) = uVar3;
  uVar4 = FUN_0000bd2c(uVar4);
  *(float *)(*(int *)(param_1 + 100) + 100) = uVar4;
  *(float *)(*(int *)(param_1 + 100) + 0x78) = uVar5;
  FUN_00103480((int)param_1);
  if (*(int *)(param_1 + 0x5c) >= DAT_002eff90 + 0x14 && *(unsigned char *)(param_1 + 0x70) != 0) {
    FUN_000ffb3c(*(undefined4 *)(param_1 + 0x68),0);
    if (((int)*(char *)(DAT_002cfc8c + 0x8b) << 0x1c) >> 0x1e == 0) {
      FUN_001b1c44((int *)&DAT_0034179c,3);
      *(undefined1 *)(param_1 + 0x70) = 0;
      *(undefined4 *)(param_1 + 0x5c) = 100;
    }
  } else {
    FUN_000ffb3c(*(undefined4 *)(param_1 + 0x68),1);
    *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) + 1;
  }
  if (!(*(int *)(param_1 + 0x5c) < DAT_002eff94)) {
    FUN_00103628((int)param_1,1);
    *(undefined1 *)(param_1 + 0x54) = 1;
    *(undefined4 *)(param_1 + 0x5c) = 0xffffffff;
  }
LAB_0021f578:
  FUN_00103128((int)param_1);
  return;
}
// near miss from lane km4 (unreviewed)
