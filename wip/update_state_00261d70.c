/* HSTMATCH module=EBOOT.BIN start=0x00261d70 end=0x00261e1c symbol=FUN_00261d70 lang=c99 */
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

extern void FUN_00102c54();

void FUN_00261d70(int param_1)
{
  uint uVar2;
  int iVar1;
  float fVar3;
  float neg;
  float half;
  float product;
  
  uVar2 = 0;
  iVar1 = param_1;
  do {
    if ((int)uVar2 >= 1 && *(int *)(param_1 + 0x2d8) < 2) goto LAB_00261dec;
    if ((int)uVar2 >= 2 && *(int *)(param_1 + 0x2d8) < 4) goto LAB_00261dec;
    fVar3 = *(float *)(iVar1 + 0x80);
    neg = -fVar3;
    half = 0.5f;
    product = neg;
    product *= half;
    *(float *)(iVar1 + 0x80) = fVar3 + product;
    FUN_00102c54(iVar1 + 0x20);
LAB_00261dec:
    iVar1 = iVar1 + 0xf0;
  } while (++uVar2 < 3);
  *(int *)(param_1 + 0x2d8) = *(int *)(param_1 + 0x2d8) + 1;
  return;
}

// NEAR MISS: one word differs at 0x00261dd4. Retail emits mul.s $f0,$f0,$f1; this source emits mul.s $f0,$f1,$f0. Other instructions match.
// near miss from lane u5cr3-1 (unreviewed)
