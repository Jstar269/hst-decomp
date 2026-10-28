/* HSTMATCH module=hstp_trans_main.prx start=0x0027732c end=0x002773c8 symbol=FUN_0027732c lang=c99 */
/* Clone of src/eboot/FUN_00266424_00266424.c (hstclone.py tag u4r4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: typed the final copied state field as float; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00055b64();
extern void FUN_00059e58();
extern void FUN_0005fec8();
extern float FUN_001340b0(float param_1,float param_2);
extern void FUN_00277794();
extern void FUN_002778c8();
extern void FUN_00277a98();

void FUN_0027732c(int param_1)
{
  int iVar1;
  float fVar2;
  
  FUN_002778c8(param_1);
  fVar2 = FUN_001340b0(*(float *)(param_1 + 0x164),*(float *)(param_1 + 0x168));
  *(float *)(param_1 + 0x164) = fVar2;
  FUN_00277a98(param_1);
  iVar1 = *(int *)(param_1 + 0x70);
  FUN_00059e58(iVar1);
  FUN_0005fec8(iVar1);
  if (*(int *)(param_1 + 0x74) != 0) {
    FUN_00055b64(*(int *)(param_1 + 0x74),(u32 *)(*(int *)(param_1 + 0x70) + 0x30));
    iVar1 = *(int *)(param_1 + 0x74);
    FUN_00059e58(iVar1);
    FUN_0005fec8(iVar1);
  }
  FUN_00277794(param_1);
  *(float *)(*(int *)(param_1 + 0x70) + 0x80) =
       *(float *)(*(int *)(param_1 + 0x70) + 0x104);
}
