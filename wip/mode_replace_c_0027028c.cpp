/* HSTMATCH module=EBOOT.BIN start=0x0027028c end=0x002704c0 symbol=FUN_0027028c lang=c++ */
typedef unsigned char undefined;
typedef unsigned char byte;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long long ulonglong;
typedef long long longlong;
typedef unsigned char uchar;
typedef unsigned long long undefined8;
typedef unsigned char undefined1;
typedef unsigned short undefined2;
typedef unsigned int undefined4;

extern "C" {
extern undefined DAT_002fe2ac;
extern undefined DAT_002fe2d0;
extern char DAT_002fe2b4[];
extern char DAT_002fe2d4[];
extern char DAT_002fe2f0[];
extern char DAT_002fe300[];
extern char DAT_0030ebf4[];
extern int FUN_00000bcc(...);
extern void FUN_000143b0(char *, char *, ...);
extern void FUN_0001ca58(...);
extern void FUN_0001cb88(...);
extern int FUN_00094fa4(...);
extern unsigned char FUN_00095104(...);
extern int FUN_002791a4(...);
extern undefined4 FUN_00279578(...);
extern void FUN_000573a0(void *, int, char *, int, int);
extern void FUN_00057b58(void *, float, int, int);
extern void FUN_00058ec4(void *, float, int);
extern void FUN_00058ddc(void *, int, int);
extern void FUN_00059084(void *, int);
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };

extern "C" void FUN_0027028c(int param_1)
{
  char buf1[256];
  char buf2[256];
  int cVar1;
  int iVar2;
  int iVar3;
  int obj;
  int *piVar5;

  iVar2 = FUN_002791a4(param_1,2);
  iVar3 = FUN_00279578(param_1,2);
  iVar2 = iVar2 + iVar3 * 4;
  if (*(int *)(param_1 + 0x180) < 0) {
    return;
  }
  {
    iVar2 = iVar2 * 0x30;
    {
      void *dup;

      dup = &DAT_002fe2ac;
      FUN_0001ca58(&DAT_0030ebf4,DAT_002fe2b4,dup,dup,
                   *(undefined4 *)(*(int *)(param_1 + 0xa8) + iVar2 + 8),&DAT_002fe2d0);
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
    cVar1 = FUN_00095104(iVar3,2,*(undefined4 *)(*(int *)(param_1 + 0xa8) + iVar2 + 8),0,0);
    FUN_0001cb88(&DAT_0030ebf4);
    if (cVar1 == '\0') {
      piVar5 = *(int **)(param_1 + 0xf0);
      if (piVar5 != (int *)0x0) {
        delete ((VC_1 *)(piVar5));
        *(undefined4 *)(param_1 + 0xf0) = 0;
      }
    }
    else if (*(int *)(*(int *)(param_1 + 0xa8) + (iVar2 + 0x14)) == 2) {
      FUN_0001ca58(&DAT_0030ebf4,DAT_002fe2d4,0);
      FUN_000143b0(buf1,DAT_002fe2f0,0);
      FUN_000143b0(buf2,DAT_002fe300,0,buf1);
      FUN_000573a0(*(void **)(param_1 + 0xf0),0,buf2,0,0);
      FUN_00057b58(*(void **)(param_1 + 0xf0),0.0f,0,0);
      obj = *(int *)(param_1 + 0xf0);
      FUN_00058ec4((void *)obj,1.0f,-1);
      *(float *)(obj + 0xc4) = 1.0f;
      obj = *(int *)(param_1 + 0xf0);
      FUN_00058ddc((void *)obj,1,-1);
      *(unsigned char *)(obj + 0xc0) = 1;
      obj = *(int *)(param_1 + 0xf0);
      FUN_00059084((void *)obj,-1);
      *(float *)(obj + 0xd0) = *(float *)(obj + 0xc4);
      FUN_0001cb88(&DAT_0030ebf4);
    }
  }
  return;
}
// NEAR 5 (141/141 words, 5 differ). Sibling function 0x002704c0 (already exact) supplied the
// overall shape: dup local for the repeated 3rd/4th print argument, `if (p) { delete p; f0 = 0; }`
// for the vtable release, and the single store after `if (new)` so MWCC duplicates it.
// Remaining deltas, both in the else-if:
//  (a) retail keeps the base load `lw a0,168(s1)` BOTH in the bnel delay slot and at the arm head
//      (a duplicate); our build hoists it into the slot and drops the arm copy, so the variant with
//      the correct addressing (`... + iVar2 + 0x14`) is one word short (140/141).
//  (b) retail's inner `beqzl a0` of the second delete targets the `b END` join (0x2703b8), ours
//      targets the epilogue directly (0x2704a8).
// Written as `... + 0x14 + iVar2` (this file) the word count is right but the field is reached with
// `addiu a0,a0,0x14; lw a0,0(a0)` instead of retail's `addu; lw a0,0x14(a0)`.
// Ruled out (all 140/141, no duplicate load): char* cast of the base, `[5]` index form, reversed
// 2 == x compare, `(iVar2 + 0x14)`, volatile field, nested `else { if }`, base local inside the arm,
// store moved outside the inner if, `int cVar1` vs `unsigned char cVar1` for the test.
// near miss from lane fm8 (unreviewed)
