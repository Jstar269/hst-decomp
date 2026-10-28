/* HSTMATCH module=hstp_trans_main.prx start=0x001251d8 end=0x0012524c symbol=FUN_001251d8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag p1), refined by hstperm.py random mutation (perm-p1/r00/f0499_001251d8_m08.c); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_0037c440;
extern void FUN_0005ffd8();

void FUN_001251d8(int param_1)
{
  int iVar2;
  int iVar1;
  
  if ((DAT_0037c440 & 0x800) != 0) {
    iVar2 = 0;
    iVar1 = param_1;
    do {
      if (*(u8 *)(param_1 + iVar2 + 0xb4) != '\0') {
        FUN_0005ffd8(*(u32 *)(iVar1 + 0x48),*(u32 *)(0xec + param_1));
      }
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 4;
    } while (iVar2 < 0x1b);
  }
}
