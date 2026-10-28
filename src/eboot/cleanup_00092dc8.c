/* HSTMATCH module=EBOOT.BIN start=0x00092dc8 end=0x00092e1c symbol=FUN_00092dc8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: test the first field directly before loading the second; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_00055e48();
extern void FUN_0005734c();

void FUN_00092dc8(int param_1)
{
  int iVar1;

  if (*(int *)(param_1 + 0x58) != 0) {
    FUN_0005734c(*(int *)(param_1 + 0x58));
  }
  iVar1 = *(int *)(param_1 + 0x6c);
  if (iVar1 != 0) {
    FUN_00055e48(iVar1,1);
    *(u32 *)(param_1 + 0x6c) = 0;
  }
  *(u32 *)(param_1 + 0x68) = 0xffffffff;
}
