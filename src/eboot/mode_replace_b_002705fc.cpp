/* HSTMATCH module=EBOOT.BIN start=0x002705fc end=0x00270738 symbol=FUN_002705fc lang=c++ */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* EXACT. Same two levers as its sibling 0x002704c0 (see that file): `void *dup = &DAT_002fe32c;`
   for the duplicated 3rd/4th argument (so `lui a2,0x30; addiu a2,a2,-7380` stays back to back),
   and ONE store after the `if` on the alloc result so MWCC duplicates it and encodes the null path
   as `beqzl v0` with the store in the delay slot. */
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
extern undefined DAT_002fe32c;
extern char DAT_002fe2b4[];
extern char DAT_0030ebf4[];
extern int FUN_00000bcc(...);
extern void FUN_0001ca58(...);
extern void FUN_0001cb88(...);
extern int FUN_00094fa4(...);
extern unsigned char FUN_00095104(...);
extern int FUN_002791a4(...);
extern undefined4 FUN_00279578(...);
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };

extern "C" void FUN_002705fc(int param_1)
{
  unsigned char cVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  
  iVar2 = FUN_002791a4(param_1,3);
  iVar3 = FUN_00279578(param_1,3);
  iVar2 = iVar2 + iVar3 * 4;
  if (*(int *)(param_1 + 0x180) < 0) {
    return;
  }
  {
    iVar2 = iVar2 * 0x30;
    {
      void *dup;

      dup = &DAT_002fe32c;
      FUN_0001ca58(&DAT_0030ebf4,DAT_002fe2b4,dup,dup,
                   *(undefined4 *)(*(int *)(param_1 + 0xc0) + iVar2 + 8),&DAT_002fe2d0);
    }
    piVar5 = *(int **)(param_1 + 0xf0);
    if (piVar5 != (int *)0x0) {
      delete ((VC_0 *)(piVar5));
      *(undefined4 *)(param_1 + 0xf0) = 0;
    }
    iVar3 = FUN_00000bcc(0x1c0);
    if (iVar3 != 0) {
      iVar3 = FUN_00094fa4(iVar3);
    }
    *(undefined4 *)(param_1 + 0xf0) = iVar3;
    uVar4 = iVar3;
    cVar1 = FUN_00095104(uVar4,3,*(undefined4 *)(*(int *)(param_1 + 0xc0) + iVar2 + 8),0,0);
    if ((cVar1 == '\0') && (piVar5 = *(int **)(param_1 + 0xf0), piVar5 != (int *)0x0)) {
      delete ((VC_1 *)(piVar5));
      *(undefined4 *)(param_1 + 0xf0) = 0;
    }
    FUN_0001cb88(&DAT_0030ebf4);
  }
  return;
}

