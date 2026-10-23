/* HSTMATCH module=EBOOT.BIN start=0x001e995c end=0x001e9c00 symbol=FUN_001e995c lang=c++ */
#pragma opt_strength_reduction off
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

extern int DAT_002ec980[];
extern volatile float DAT_002ed27c;
extern volatile int DAT_002ed2b4;
extern volatile int DAT_002ed2b8;
extern void * volatile DAT_00338b44;
extern "C" {
void FUN_000ee510(undefined4, int, int, int, int);
void FUN_000ffb3c(undefined4, int);
}

static inline float Clamp(const volatile int &lower, const float &value, const volatile int &upper)
{
  if (value < (float)lower)
    return (float)lower;
  if ((float)upper < value)
    return (float)upper;
  return value;
}

static inline int tableValue(const int &index)
{
  return DAT_002ec980[index * 3 + 2];
}

extern "C" void FUN_001e995c(int param_1)
{
  int iVar6;
  int iVar9;
  int iVar7;
  int iVar1;
  register int *piVar8;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float fVar10;
  int *local_4;
  
  fVar10 = (float)*(int *)(param_1 + 0x440) - DAT_002ed27c;
  local_4 = (int *)(param_1 + 0x3a4);
  piVar8 = (int *)(param_1 + 0x39c);
  fVar10 = Clamp(DAT_002ed2b4, fVar10, DAT_002ed2b8);
  for (iVar6 = 0, iVar9 = 0x30; iVar6 < 2; iVar6++, iVar9 += 3, local_4 += 6, piVar8++) {
    iVar1 = -(uint)(*(int *)((char *)DAT_00338b44 + 0xa4) == iVar6);
    iVar7 = 0;
    do {
      iVar5 = iVar1;
      if (iVar7 != 0) {
        iVar5 = 0;
      }
      iVar5 = tableValue(iVar7 + iVar9) + *piVar8 + iVar5;
      iVar3 = param_1 + (iVar7 + iVar9) * 4;
      iVar2 = *(int *)(iVar3 + 0x7c);
      *(int *)(iVar2 + 0x24) = iVar5;
      *(int *)(iVar2 + 0x28) = iVar5;
      FUN_000ffb3c(*(undefined4 *)(iVar3 + 0x7c),0);
      iVar5 = (int)fVar10;
      if (iVar1 == 0) {
        iVar5 = 0;
      }
      FUN_000ee510(*(undefined4 *)(iVar3 + 0x7c),iVar6,iVar7,iVar5,1);
    } while (++iVar7 < 3);
    iVar1 = -(uint)(*(int *)((char *)DAT_00338b44 + 0xa0) == iVar6);
    if (*(char *)(param_1 + 0x419) == '\0') {
      iVar7 = 0;
    }
    else {
      iVar7 = *(int *)(param_1 + 0x398) + -1;
    }
    iVar5 = 0;
    do {
      iVar3 = iVar5 + iVar6 * 3 + 0x36;
      iVar2 = iVar1;
      if (iVar5 != 0) {
        iVar2 = 0;
      }
      iVar2 = tableValue(iVar3) + local_4[iVar7] + iVar2;
      iVar4 = param_1 + iVar3 * 4;
      iVar3 = *(int *)(iVar4 + 0x7c);
      *(int *)(iVar3 + 0x24) = iVar2;
      *(int *)(iVar3 + 0x28) = iVar2;
      FUN_000ffb3c(*(undefined4 *)(iVar4 + 0x7c),0);
      iVar2 = (int)fVar10;
      if (iVar1 == 0) {
        iVar2 = 0;
      }
      FUN_000ee510(*(undefined4 *)(iVar4 + 0x7c),iVar6 + 2,iVar5,iVar2,1);
    } while (++iVar5 < 3);
  }
  *(int *)(param_1 + 0x440) = *(int *)(param_1 + 0x440) + 1;
  return;
}

// Best result: 137 differing words out of 169; first mismatch at +0x30.
// Remaining differences are in clamp instruction order and loop register/branch layout.
// Ruled out byte, struct, and scalar table views; C and C++ modes; strength-reduction toggles; pointer-live-range variants; and for/do loop forms. The volatile-bound reference clamp is best so far.
// near miss from lane km4 (unreviewed)
