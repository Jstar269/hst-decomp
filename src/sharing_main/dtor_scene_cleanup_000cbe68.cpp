/* HSTMATCH module=hstp_trans_main.prx start=0x000cbe68 end=0x000cc190 symbol=FUN_000cbe68 lang=c++ */
/* Clone of src/eboot/dtor_scene_cleanup_000c82c8.cpp (hstclone.py tag c45): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: FUN_00059ca4 takes -1 as its second argument (shared with the id store), FUN_0005ff00(float, obj), delete[] argument, loop index/pointer in their own block-scope variables, vector clear as shrink(n, Alloc()) via a Vec cast, opt_strength_reduction off; exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
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
extern undefined DAT_003b0868;
extern undefined * DAT_003e19f0;
extern void FUN_000006e8(...);
extern void FUN_00000788(...);
extern void FUN_000009e4(int);
extern void FUN_00000a00(...);
extern undefined4 * FUN_0001ed28(...);
extern int FUN_000541d8(...);
extern int FUN_000569f4(...);
extern void FUN_00059ca4(int, int);
extern int FUN_0005c688(...);
extern void FUN_0005ff00(float, int);
extern int * FUN_00064d08(...);
extern void FUN_00068cf4(...);
extern int * FUN_000702c4(...);
extern void FUN_000cba70(...);
extern int FUN_000d9998(...);
extern void FUN_00057904(...);
extern void FUN_000cb288(...);
extern void FUN_000cb2f4(...);
}
struct Alloc {};
struct Vec { int **data; unsigned size; void shrink(int n, Alloc) { size -= n; } };
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };
struct VC_2 { virtual ~VC_2(); };
struct VC_3 { virtual ~VC_3(); };
struct VC_4 { virtual ~VC_4(); };
struct VC_5 { virtual ~VC_5(); };

extern "C" undefined4 * FUN_000cbe68(undefined4 *param_1,short param_2)
{
  int *piVar2;
  undefined4 *puVar4;
  int iVar3;
  uint uVar5;
  
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b0868);
    if (param_1[0x70] != 0) {
      *(undefined1 *)(param_1 + 0x71) = 0;
      param_1[0x72] = 0xffffffff;
      iVar3 = param_1[0x70];
      if (iVar3 != 0) {
        FUN_00059ca4(iVar3, -1);
        FUN_0005ff00(0.0f,iVar3);
        *(undefined4 *)(iVar3 + 0xd0) = 0;
      }
    }
    if (DAT_003e19f0 != 0) {
      FUN_00068cf4(*(undefined4 *)(*(int *)(DAT_003e19f0 + 0x90) + 0x44));
    }
    {
      int i;
      undefined4 *p;
      i = 0;
      p = param_1;
      do {
        piVar2 = (int *)p[0x59];
        if (piVar2 != (int *)0x0) {
          delete ((VC_0 *)(piVar2));
          p[0x59] = 0;
        }
        piVar2 = (int *)p[99];
        if (piVar2 != (int *)0x0) {
          delete ((VC_1 *)(piVar2));
          p[99] = 0;
        }
        i = i + 1;
        p = p + 1;
      } while (i < 10);
    }
    if (param_1[0x17] != 0) {
      FUN_0005c688(param_1[0x17],1);
      param_1[0x17] = 0;
    }
    iVar3 = param_1[0x1c];
    if (iVar3 != 0) {
      FUN_00064d08(iVar3,1);
      param_1[0x1c] = 0;
    }
    piVar2 = (int *)param_1[0x1d];
    if (piVar2 != (int *)0x0) {
      delete ((VC_2 *)(piVar2));
      param_1[0x1d] = 0;
    }
    piVar2 = (int *)param_1[0x1e];
    if (piVar2 != (int *)0x0) {
      delete ((VC_3 *)(piVar2));
      param_1[0x1e] = 0;
    }
    uVar5 = 0;
    if (param_1[0x6e] != 0) {
      do {
        piVar2 = *(int **)(param_1[0x6d] + uVar5 * 4);
        if (piVar2 != (int *)0x0) {
          delete ((VC_4 *)(piVar2));
          *(undefined4 *)(param_1[0x6d] + uVar5 * 4) = 0;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < param_1[0x6e]);
    }
    {
      int n = ((Vec *)(param_1 + 0x6d))->size;
      ((Vec *)(param_1 + 0x6d))->shrink(n, Alloc());
    }
    if (param_1[0x74] != 0) {
      FUN_000006e8(param_1[0x74],FUN_00057904);
      param_1[0x74] = 0;
    }
    iVar3 = param_1[0x75];
    if (iVar3 != 0) {
      FUN_000009e4(iVar3);
      param_1[0x75] = 0;
    }
    iVar3 = param_1[0x77];
    if (iVar3 != 0) {
      FUN_000569f4(iVar3,1);
      param_1[0x77] = 0;
    }
    iVar3 = param_1[0x76];
    if (iVar3 != 0) {
      FUN_000541d8(iVar3,1);
      param_1[0x76] = 0;
    }
    piVar2 = (int *)param_1[0x70];
    if (piVar2 != (int *)0x0) {
      delete ((VC_5 *)(piVar2));
      param_1[0x70] = 0;
    }
    FUN_000cba70(param_1);
    puVar4 = param_1 + 0xb8;
    if ((((puVar4 != (undefined4 *)0x0) && (puVar4 != (undefined4 *)0x0)) &&
        (puVar4 != (undefined4 *)0x0)) && (puVar4 != (undefined4 *)0x0)) {
      FUN_000d9998(puVar4,0);
    }
    FUN_00000788(param_1 + 0x88,FUN_000cb288,0xc,0x10);
    FUN_00000788(param_1 + 0x78,FUN_000cb2f4,0x10,4);
    puVar4 = param_1 + 0x6d;
    if ((puVar4 != (undefined4 *)0x0) && (puVar4 != (undefined4 *)0x0)) {
      FUN_000702c4(puVar4,0);
    }
    FUN_0001ed28(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
