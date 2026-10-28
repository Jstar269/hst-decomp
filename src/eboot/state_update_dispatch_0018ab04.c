/* HSTMATCH module=EBOOT.BIN start=0x0018ab04 end=0x0018abec symbol=FUN_0018ab04 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: the if/else-if chain on the state rewritten as a switch with cases 0..4 in source order (empty case 4); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_002cfc8c;
extern u8 FUN_0001eb44();
extern void FUN_000ffb3c();
extern void FUN_00103128();
extern void FUN_00103480();
extern void FUN_0018abec();
extern void FUN_0018ad0c();
extern void FUN_0018b1d0();
extern void FUN_0018b2bc();

void FUN_0018ab04(int param_1)
{
  u8 bVar1;
  int iVar2;
  u32 uVar3;
  
  uVar3 = (u32)(*(int *)(param_1 + 0x54) != 2);
  if (uVar3 == 0) {
    uVar3 = (u32)(0 < *(int *)(param_1 + 0x60));
  }
  FUN_000ffb3c(*(int *)(param_1 + 0x74),uVar3);
  bVar1 = FUN_0001eb44(DAT_002cfc8c,(u32 *)(param_1 + 0x68),0x4000);
  *(u8 *)(param_1 + 0x70) = bVar1;
  iVar2 = *(int *)(param_1 + 0x54);
  switch (iVar2) {
  case 0:
    FUN_0018abec(param_1);
    break;
  case 1:
    FUN_0018ad0c(param_1);
    break;
  case 2:
    FUN_0018b1d0(param_1);
    break;
  case 3:
    FUN_0018b2bc(param_1);
    break;
  case 4:
    break;
  }
  FUN_00103480(param_1);
  FUN_00103128(param_1);
}
