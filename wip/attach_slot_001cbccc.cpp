/* HSTMATCH module=EBOOT.BIN start=0x001cbccc end=0x001cbedc symbol=FUN_001cbccc lang=c++ */
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
extern undefined DAT_002c0e18;
extern undefined DAT_002c0e1c;
extern undefined DAT_002c0e20;
extern void FUN_0018a950(...);
extern undefined1 * FUN_0018c9f4(...);
extern void FUN_001cd88c(...);
extern undefined * FUN_002294f4(int, int, undefined4, int);
extern undefined4 FUN_002297d8(...);
extern int * FUN_00288a84(...);
}
struct VC_0 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual int m(); };
struct VC_1 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual int m(); };
struct VC_2 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void d7(); virtual void d8(); virtual void d9(); virtual void d10(); virtual void d11(); virtual void d12(); virtual void d13(); virtual void d14(); virtual void d15(); virtual void d16(); virtual void d17(); virtual void d18(); virtual void d19(); virtual void d20(); virtual void d21(); virtual void d22(); virtual void d23(); virtual void d24(); virtual void d25(); virtual void d26(); virtual void d27(); virtual void d28(); virtual void d29(); virtual void d30(); virtual void m(int, int); };

extern "C" void FUN_001cbccc(int param_1,int *param_2,undefined4 param_3,int param_4)
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined *puVar5;
  
  if (param_2 != (int *)0x0) {
    if (param_4 < 0) {
      iVar3 = param_2[0xd];
      iVar2 = (int)(FUN_0018c9f4(7));
      if (*(int *)(iVar2 + 4) == 0) {
        puVar5 = &DAT_002c0e20;
      }
      else if (*(int *)(*(int *)(iVar2 + 8) + 8) < 1) {
        puVar5 = &DAT_002c0e1c;
      }
      else if ((iVar3 < 0) || (iVar3 >= (*(int **)(iVar2 + 0xc))[1])) {
        puVar5 = &DAT_002c0e18;
      }
      else {
        puVar5 = *(undefined **)(**(int **)(iVar2 + 0xc) + iVar3 * 4);
      }
      iVar2 = *(int *)(param_1 + 0x15c);
    }
    else {
      iVar2 = (int)(FUN_0018c9f4(0xc));
      if (*(int *)(iVar2 + 4) == 0) {
        puVar5 = &DAT_002c0e20;
      }
      else if (*(int *)(*(int *)(iVar2 + 8) + 8) < 1) {
        puVar5 = &DAT_002c0e1c;
      }
      else if ((param_4 < 0) || (param_4 >= (*(int **)(iVar2 + 0xc))[1])) {
        puVar5 = &DAT_002c0e18;
      }
      else {
        puVar5 = *(undefined **)(**(int **)(iVar2 + 0xc) + param_4 * 4);
      }
      iVar2 = *(int *)(param_1 + 0x15c);
    }
    iVar3 = (int)(FUN_002294f4(iVar2 + 0x34,*(undefined4 *)(iVar2 + 0x24),param_3,0));
    if (iVar3 != 0) {
      *(undefined1 *)(iVar2 + 99) = 0;
      *(undefined1 *)(iVar2 + 100) = 0;
      *(int *)(iVar2 + 0x68) = iVar3;
      *(undefined4 *)(iVar2 + 0x6c) = 0;
      *(undefined4 *)(iVar2 + 0x70) = 0;
      FUN_0018a950(*(undefined4 *)(iVar2 + 0x20),puVar5);
      FUN_001cd88c(iVar2,2,1);
    }
    *(undefined4 *)(iVar2 + 0x74) = 0xffffffff;
    *(undefined4 *)(iVar2 + 0x78) = 0xffffffff;
    FUN_002297d8(iVar2 + 0x34,param_3,0);
    iVar2 = ((VC_0 *)(param_2))->m();
    bVar1 = iVar2 == 2;
    if (!bVar1) {
      iVar2 = ((VC_1 *)(param_2))->m();
      bVar1 = iVar2 == 3;
    }
    if (bVar1) {
      piVar4 = (int *)FUN_00288a84(param_2);
      ((VC_2 *)(piVar4))->m((int)(0), (int)(1));
      *(int **)(*(int *)(param_1 + 0x15c) + 0x5c) = param_2;
    }
  }
  return;
}
// near miss: 132/132 words, 4 differing - the only delta is the argument-setup order of the
// FUN_002294f4 call at 0x001cbe00. Retail emits `move a2,s1; move a3,zero; lw a1,36(s0); jal`
// (with `addiu a0,s0,52` in the jal delay slot); we emit `lw a1,36(s0); addiu a0,s0,52;
// move a2,s1; jal` (a3 in the delay slot). Same instructions, different schedule.
// FIXED along the way (from the 8-word draft): the index bounds test. `(i < 0) || (count <= i)`
// compiles the second compare into `at` (`slt at,s0,v0; bnezl at`), while the equivalent
// `(i < 0) || (i >= count)` gives retail's `slt v0,s0,v0; bnezl v0`. Splitting the condition into
// two else-ifs that repeat the default arm is 4 words longer and wrong (136 vs 132).
// Also tried for the arg order, all still 4 words: a typed prototype for FUN_002294f4, and
// declaring its 3rd parameter a void* (register-class changes do not reorder these).
// 2026-10-24 re-check: still 132/132 words, the same 4 differing words at 0x001cbdec - only the
// argument-setup order of the FUN_002294f4 call. Retail: `move a2,s1; move a3,zero; lw a1,36(s0);
// addiu a0,s0,52` (a2/a3 first); ours: `lw a1,36(s0); addiu a0,s0,52; move a2,s1; move a3,zero`.
// Giving FUN_002294f4 a real prototype (int,int,undefined4,int instead of `(...)`) changed nothing.
// near miss from lane fm9 (unreviewed)
