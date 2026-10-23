/* HSTMATCH module=EBOOT.BIN start=0x002704c0 end=0x002705fc symbol=FUN_002704c0 lang=c++ */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned long long undefined8;
typedef int code(...);
#define ABS(x) ((x) < 0 ? -(x) : (x))
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern "C" {
extern undefined DAT_002fe2d0;
extern undefined DAT_002fe324;
extern char DAT_002fe2b4[];
extern int FUN_00000bcc(...);
extern void FUN_0001ca58(...);
extern void FUN_0001cb88(...);
extern undefined4 * FUN_00094fa4(...);
extern char FUN_00095104(...);
extern int FUN_002791a4(...);
extern undefined4 FUN_00279578(...);
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };

extern "C" void FUN_002704c0(int param_1)
{
  char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  
  iVar2 = FUN_002791a4(param_1,1);
  iVar3 = FUN_00279578(param_1,1);
  if (-1 < *(int *)(param_1 + 0x180)) {
    iVar2 = (iVar2 + iVar3 * 4) * 0x30;
    FUN_0001ca58(0x30ebf4,DAT_002fe2b4,&DAT_002fe324,&DAT_002fe324,
                 *(undefined4 *)(*(int *)(param_1 + 0xb4) + iVar2 + 8),&DAT_002fe2d0);
    piVar5 = *(int **)(param_1 + 0xf0);
    if (piVar5 != (int *)0x0) {
      delete ((VC_0 *)(piVar5));
      *(undefined4 *)(param_1 + 0xf0) = 0;
    }
    iVar3 = FUN_00000bcc(0x1c0);
    if (iVar3 == 0) {
      *(undefined4 *)(param_1 + 0xf0) = 0;
      uVar4 = 0;
    }
    else {
      uVar4 = (unsigned int)(FUN_00094fa4(iVar3));
      *(undefined4 *)(param_1 + 0xf0) = uVar4;
    }
    cVar1 = FUN_00095104(uVar4,1,*(undefined4 *)(*(int *)(param_1 + 0xb4) + iVar2 + 8),0,0);
    FUN_0001cb88(0x30ebf4);
    if ((cVar1 == '\0') && (piVar5 = *(int **)(param_1 + 0xf0), piVar5 != (int *)0x0)) {
      delete ((VC_1 *)(piVar5));
      *(undefined4 *)(param_1 + 0xf0) = 0;
    }
  }
  return;
}

// NEAR MISS: 84/79 words. Retail: two query calls FUN_002791a4(self,1) and
// FUN_00279578(self,1), index = (first + second*4) * 48, then a 6-argument log call
// FUN_0001ca58(&DAT_0030ebf4, &DAT_002fe2b4, &DAT_002fe324, &DAT_002fe324,
// *(int*)(*(int*)(self+0xb4) + idx + 8), &DAT_002fe2d0); then the managed-object replace:
// virtual dtor call (t9 = *p; t9 = *(t9+8); jalr t9) with a1 = 1 on the old self->f0,
// self->f0 = 0, `p = FUN_00000bcc(448)`, `if (p) FUN_00094fa4(p)`, self->f0 = p,
// `c = FUN_00095104(p,1,*(int*)(*(int*)(self+0xb4) + idx + 8),0,0)`, FUN_0001cb88(&DAT_0030ebf4),
// and a second virtual-dtor site when c == 0. 0x002705fc is the same shape with a1 = 3
// instead of 1, field 0xc0 instead of 0xb4 and the unlog call after the null test.
// near miss from lane fm5 (unreviewed)
