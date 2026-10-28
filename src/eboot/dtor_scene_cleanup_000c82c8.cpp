/* HSTMATCH module=EBOOT.BIN start=0x000c82c8 end=0x000c85f0 symbol=FUN_000c82c8 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: FUN_00058fc0 takes -1 as its second argument (shared with the id store), FUN_0005f110(float, obj), delete[] argument, loop index/pointer in their own block-scope variables, vector clear as shrink(n, Alloc()) via a Vec cast, opt_strength_reduction off; exact match verified; names and types await human review. */
#pragma opt_strength_reduction off
#include "hst/types.h"

extern "C" {
extern u8 DAT_0030759c;
extern u8 * DAT_003386b0;
extern void FUN_000006e8(...);
extern void FUN_00000788(...);
extern void FUN_000009e4(int);
extern void FUN_00000a00(...);
extern u32 * FUN_0001f0f0(...);
extern int FUN_00053718(...);
extern int FUN_00055e48(...);
extern void FUN_00058fc0(int, int);
extern int FUN_0005ba00(...);
extern void FUN_0005f110(float, int);
extern int * FUN_00063e44(...);
extern void FUN_000678a0(...);
extern int * FUN_0006eb04(...);
extern void FUN_000c7ed0(...);
extern int FUN_000d5ca8(...);
extern void FUN_00056cb0(...);
extern void FUN_000c77a8(...);
extern void FUN_000c7814(...);
}
struct Alloc {};
struct Vec { int **data; unsigned size; void shrink(int n, Alloc) { size -= n; } };
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };
struct VC_2 { virtual ~VC_2(); };
struct VC_3 { virtual ~VC_3(); };
struct VC_4 { virtual ~VC_4(); };
struct VC_5 { virtual ~VC_5(); };

extern "C" u32 * FUN_000c82c8(u32 *param_1,short param_2)
{
  int *piVar2;
  u32 *puVar4;
  int iVar3;
  u32 uVar5;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_0030759c);
    if (param_1[0x70] != 0) {
      *(u8 *)(param_1 + 0x71) = 0;
      param_1[0x72] = 0xffffffff;
      iVar3 = param_1[0x70];
      if (iVar3 != 0) {
        FUN_00058fc0(iVar3, -1);
        FUN_0005f110(0.0f,iVar3);
        *(u32 *)(iVar3 + 0xd0) = 0;
      }
    }
    if (DAT_003386b0 != 0) {
      FUN_000678a0(*(u32 *)(*(int *)(DAT_003386b0 + 0x90) + 0x44));
    }
    {
      int i;
      u32 *p;
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
      FUN_0005ba00(param_1[0x17],1);
      param_1[0x17] = 0;
    }
    iVar3 = param_1[0x1c];
    if (iVar3 != 0) {
      FUN_00063e44(iVar3,1);
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
          *(u32 *)(param_1[0x6d] + uVar5 * 4) = 0;
        }
        uVar5 = uVar5 + 1;
      } while (uVar5 < param_1[0x6e]);
    }
    {
      int n = ((Vec *)(param_1 + 0x6d))->size;
      ((Vec *)(param_1 + 0x6d))->shrink(n, Alloc());
    }
    if (param_1[0x74] != 0) {
      FUN_000006e8(param_1[0x74],FUN_00056cb0);
      param_1[0x74] = 0;
    }
    iVar3 = param_1[0x75];
    if (iVar3 != 0) {
      FUN_000009e4(iVar3);
      param_1[0x75] = 0;
    }
    iVar3 = param_1[0x77];
    if (iVar3 != 0) {
      FUN_00055e48(iVar3,1);
      param_1[0x77] = 0;
    }
    iVar3 = param_1[0x76];
    if (iVar3 != 0) {
      FUN_00053718(iVar3,1);
      param_1[0x76] = 0;
    }
    piVar2 = (int *)param_1[0x70];
    if (piVar2 != (int *)0x0) {
      delete ((VC_5 *)(piVar2));
      param_1[0x70] = 0;
    }
    FUN_000c7ed0(param_1);
    puVar4 = param_1 + 0xb8;
    if ((((puVar4 != (u32 *)0x0) && (puVar4 != (u32 *)0x0)) &&
        (puVar4 != (u32 *)0x0)) && (puVar4 != (u32 *)0x0)) {
      FUN_000d5ca8(puVar4,0);
    }
    FUN_00000788(param_1 + 0x88,FUN_000c77a8,0xc,0x10);
    FUN_00000788(param_1 + 0x78,FUN_000c7814,0x10,4);
    puVar4 = param_1 + 0x6d;
    if ((puVar4 != (u32 *)0x0) && (puVar4 != (u32 *)0x0)) {
      FUN_0006eb04(puVar4,0);
    }
    FUN_0001f0f0(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
