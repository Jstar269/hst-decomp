/* HSTMATCH module=hstp_trans_main.prx start=0x0029f4e4 end=0x0029f6dc symbol=FUN_0029f4e4 lang=c++ */
/* Clone of src/eboot/FUN_0028dd1c_0028dd1c.cpp (hstclone.py tag u4r4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag gen-a5/v17) corrected by hand: typed the four source fields as signed short to select halfword loads; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_003a7e8c;
extern u8 DAT_003a7e98;
extern u8 DAT_003b304c;
extern char DAT_003a7e90[];
extern char DAT_003a7e9c[];
extern char DAT_003a7ea8[];
extern char DAT_003a7eb8[];
extern char DAT_003a7ec8[];
extern char DAT_003a7ed4[];
extern char DAT_003a7ee0[];
extern char DAT_003a7eec[];
extern char DAT_003a7ef8[];
extern char DAT_003a7f04[];
extern char DAT_003a7f10[];
extern void FUN_00105470(...);
extern int FUN_00108124(...);
extern int FUN_00109304(...);
extern u32 * FUN_00268090(...);
extern void FUN_0029134c(...);
}
struct VC_0 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void m(int); };
struct VC_1 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void m(int); };
struct VC_2 { virtual void d0(); virtual void d1(); virtual void d2(); virtual void d3(); virtual void d4(); virtual void d5(); virtual void d6(); virtual void m(); };

extern "C" int * FUN_0029f4e4(int *param_1)
{
  u32 uVar1;
  int iVar2;
  int *piVar3;
  
  FUN_00268090();
  *param_1 = (int)&DAT_003b304c;
  param_1[0x61b] = 0;
  *(u16 *)(param_1 + 0x61c) = 0;
  param_1[0x61d] = 0;
  *(u8 *)(param_1 + 0x61e) = 0;
  param_1[0x61f] = 0;
  *(u16 *)(param_1 + 0x620) = 0;
  param_1[0x621] = 0;
  *(u8 *)(param_1 + 0x622) = 0;
  uVar1 = FUN_00109304(param_1,&DAT_003a7e8c,0);
  iVar2 = FUN_00108124(uVar1,DAT_003a7e90);
  param_1[0x617] = iVar2;
  iVar2 = FUN_00109304(param_1,&DAT_003a7e98,0);
  param_1[0x6e6] = iVar2;
  iVar2 = FUN_00108124(iVar2,DAT_003a7e9c);
  param_1[0x6e5] = *(int *)(iVar2 + 0x20);
  iVar2 = FUN_00108124(param_1[0x6e6],DAT_003a7ea8);
  param_1[0x619] = iVar2;
  iVar2 = FUN_00108124(param_1[0x6e6],DAT_003a7eb8);
  param_1[0x61a] = iVar2;
  FUN_0029134c(param_1 + 0x61b,param_1[0x619],1);
  FUN_0029134c(param_1 + 0x61f,param_1[0x61a],0);
  iVar2 = FUN_00108124(param_1[0x6e6],DAT_003a7ec8);
  piVar3 = *(int **)(iVar2 + 0x20);
  param_1[0x623] = (int)piVar3;
  ((VC_0 *)(piVar3))->m((int)(0x80000000));
  iVar2 = FUN_00108124(param_1[0x6e6],DAT_003a7ed4);
  piVar3 = *(int **)(iVar2 + 0x20);
  param_1[0x624] = (int)piVar3;
  ((VC_1 *)(piVar3))->m((int)(0x80000000));
  iVar2 = FUN_00108124(param_1[0x194],DAT_003a7ee0);
  param_1[0x6e7] = iVar2;
  iVar2 = FUN_00108124(param_1[0x194],DAT_003a7eec);
  param_1[0x6e8] = iVar2;
  iVar2 = FUN_00108124(param_1[0x194],DAT_003a7ef8);
  param_1[0x6e9] = iVar2;
  iVar2 = FUN_00108124(param_1[0x194],DAT_003a7f04);
  param_1[0x6ea] = iVar2;
  *(u16 *)(param_1 + 0x6eb) = *(short *)(param_1[0x6e7] + 4);
  *(u16 *)((int)param_1 + 0x1bae) = *(short *)(param_1[0x6e8] + 4);
  *(u16 *)(param_1 + 0x6ec) = *(short *)(param_1[0x6e9] + 4);
  *(u16 *)((int)param_1 + 0x1bb2) = *(short *)(param_1[0x6ea] + 4);
  iVar2 = FUN_00108124(param_1[0x194],DAT_003a7f10);
  param_1[0x6ed] = iVar2;
  FUN_00105470(param_1[0x1aa],1);
  param_1[0x614] = 0;
  ((VC_2 *)(param_1))->m();
  return param_1;
}
