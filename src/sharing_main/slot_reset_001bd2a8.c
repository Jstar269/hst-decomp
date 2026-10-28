/* HSTMATCH module=hstp_trans_main.prx start=0x001bd2a8 end=0x001bd3ac symbol=FUN_001bd2a8 lang=c99 */
/* Clone of src/eboot/slot_reset_001afbd0.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: while (iVar3 >= 0) loop test, declaration order (pointer after the index), the two small clear loops written with block-scoped counter and pointer, with opt_unroll_loops and opt_strength_reduction off (rolled loops); exact match verified; names and types await human review. */
#pragma opt_unroll_loops off
#pragma opt_strength_reduction off
#include "hst/types.h"

extern int FUN_00063304();

void FUN_001bd2a8(int param_1)
{
  u32 uVar1;
  int iVar3;
  int *piVar2;
  
  iVar3 = 0x1d9;
  piVar2 = (int *)(param_1 + 0x764);
  do {
    if ((iVar3 != 0x58) && (*piVar2 != 0)) {
      FUN_00063304(*piVar2,1);
      *piVar2 = 0;
    }
    iVar3 = iVar3 + -1;
    piVar2 = piVar2 + -1;
  } while (iVar3 >= 0);
  *(u32 *)(param_1 + 0x79c) = 0xffffffff;
  *(u32 *)(param_1 + 0x7a0) = 0xffffffff;
  *(u32 *)(param_1 + 0x7a4) = 0xffffffff;
  *(u32 *)(param_1 + 0x7a8) = 0xffffffff;
  *(u32 *)(param_1 + 0x7ac) = 0xffffffff;
  *(u32 *)(param_1 + 0x7b0) = 0x1da;
  *(u32 *)(param_1 + 0x7b4) = 0xffffffff;
  *(u32 *)(param_1 + 0x7b8) = 0x1da;
  *(u32 *)(param_1 + 0x7bc) = 0xffffffff;
  *(u32 *)(param_1 + 0x7c0) = 0x1da;
  *(u32 *)(param_1 + 0x7c4) = 0xffffffff;
  *(u32 *)(param_1 + 0x7c8) = 0x1da;
  uVar1 = 0;
  iVar3 = param_1;
  do {
    *(u32 *)(iVar3 + 0x768) = 0;
    *(u8 *)(param_1 + uVar1 + 0x798) = 0;
    uVar1 = uVar1 + 1;
    iVar3 = iVar3 + 4;
  } while (uVar1 < 4);
  {
    u32 k = 0;
    int p = param_1;
    do {
      k = k + 1;
      *(u32 *)(p + 0x778) = 0;
      p = p + 4;
    } while (k < 4);
  }
  *(u32 *)(param_1 + 0x788) = 0;
  {
    u32 k = 0;
    int p = param_1;
    do {
      k = k + 1;
      *(u32 *)(p + 0x78c) = 0;
      p = p + 4;
    } while (k < 2);
  }
  *(u32 *)(param_1 + 0x794) = 0;
}
