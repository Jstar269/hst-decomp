/* HSTMATCH module=EBOOT.BIN start=0x0022d67c end=0x0022d848 symbol=FUN_0022d67c__FPc lang=c99 */
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

extern undefined DAT_002f33c4;
extern char DAT_002f34bc[];
extern char DAT_002f34e8[];
extern char DAT_002f3510[];
extern undefined4 DAT_0034179c;
extern undefined DAT_0030ab9c;
extern undefined4 DAT_0030820c;
extern undefined4 DAT_00308228;
extern undefined DAT_0030ebf4;
extern int FUN_00010184(int, int);
extern void FUN_000104e0(undefined4);
extern void FUN_000143b0(void *, void *, int);
extern void FUN_0001bfb4(void *, undefined4, int);
extern void FUN_0001ca58(void *, void *);
extern void FUN_0001cb88(void *);
extern int FUN_0001cbfc();
extern undefined4 FUN_0001cc54();
extern void FUN_001b2430(void *);
extern void FUN_001b3068(void *);
extern void FUN_001b3138(void *, int);
extern void FUN_001b3140(void *);
extern void FUN_001b3148(void *, int);
extern void FUN_001b31ac(void *);
extern void FUN_001b3e2c(void *);

void FUN_0022d67c(char *param_1)
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  undefined1 auStack_100 [256];
  
  iVar5 = *(int *)(*(int *)(param_1 + 0x2cc) + *(int *)(param_1 + 600) * 4);
  FUN_001b3e2c(&DAT_0034179c);
  FUN_001b2430(&DAT_0034179c);
  iVar4 = *(int *)(param_1 + 0xb4);
  if (iVar4 != -1) goto initialization_done;
  {
    uVar1 = FUN_00010184(0x40,0xccccc);
    FUN_0001bfb4(&DAT_0030ab9c,uVar1,0xccccc);
    FUN_001b3068(&DAT_0034179c);
    uVar2 = FUN_0001cbfc();
    uVar3 = FUN_0001cc54();
    FUN_0001bfb4(&DAT_0030ab9c,uVar2,uVar3);
    FUN_000104e0(uVar1);
  }
initialization_done:
  if (*(int *)(param_1 + 0xb4) == iVar5) {
    *(int *)(param_1 + 0xb4) = iVar5;
  }
  else {
    FUN_001b3140(&DAT_0034179c);
    FUN_001b31ac(&DAT_0034179c);
    if (iVar5 < 0xf) {
      if (iVar5 == 0xe) {
        FUN_000143b0(auStack_100,DAT_002f34bc,0xe);
      }
      else {
        FUN_000143b0(auStack_100,DAT_002f34e8,iVar5);
      }
      FUN_0001ca58(&DAT_0030ebf4,auStack_100);
      FUN_001b3138(&DAT_0034179c,iVar5);
      FUN_0001cb88(&DAT_0030ebf4);
    }
    else {
      FUN_000143b0(auStack_100,DAT_002f3510,
                   *(undefined4 *)(&DAT_002f33c4 + (iVar5 + -0xf) * 4));
      FUN_0001ca58(&DAT_0030ebf4,auStack_100);
      FUN_001b3148(&DAT_0034179c,*(undefined4 *)(&DAT_002f33c4 + (iVar5 + -0xf) * 4));
      FUN_0001cb88(&DAT_0030ebf4);
    }
    *(int *)(param_1 + 0xb4) = iVar5;
  }
  *(undefined4 *)(param_1 + 0xac) = 0;
  return;
}

// Best result: 19 differing words out of 115; first mismatch at +0xc0.
// Remaining differences are branch-likely direction and register reuse in the state comparison/update block.
// Ruled out direct comparisons, early-goto forms, shared return stores, and C/C++ modes; the near miss keeps symbolic addresses for all absolute data references.
// near miss from lane km4 (unreviewed)
// improved by lane fm10 (unreviewed): no comparable result -> 19 differing words
