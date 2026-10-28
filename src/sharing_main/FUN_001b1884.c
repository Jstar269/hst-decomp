/* HSTMATCH module=hstp_trans_main.prx start=0x001b1884 end=0x001b1900 symbol=FUN_001b1884 lang=c99 */
/* Clone of src/eboot/FUN_001a42b8.c (hstclone.py tag u4r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: inverted dispatch condition and widened comparison flag to int; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00177c64();
extern int FUN_001b1900();

void FUN_001b1884(int param_1,int param_2)
{
  int bVar1;
  int iVar2;
  
  if (param_2 != 0) {
    iVar2 = **(int **)(*(int *)(param_1 + 900) + *(int *)(param_1 + 0x300) * 4);
    bVar1 = iVar2 == -1;
    if (bVar1) {
      iVar2 = FUN_001b1900();
    }
    FUN_00177c64(iVar2,bVar1);
  }
  else {
    *(u32 *)(param_1 + 0x2fc) = *(u32 *)(param_1 + 0x308);
    *(u32 *)(param_1 + 0x300) = *(u32 *)(param_1 + 0x30c);
    *(u32 *)(param_1 + 0x304) = *(u32 *)(param_1 + 0x310);
  }
}
