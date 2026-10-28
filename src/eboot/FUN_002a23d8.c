/* HSTMATCH module=EBOOT.BIN start=0x002a23d8 end=0x002a2434 symbol=FUN_002a23d8 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag a2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0034179c;
extern int FUN_001b1c44();
extern void FUN_002a1f60();

void FUN_002a23d8(int param_1)
{
  int *piVar1;
  
  if ((*(int *)(param_1 + 0x1b0) == 5) && (piVar1 = *(int **)(param_1 + 0x1d0), *piVar1 == 1)) {
    FUN_001b1c44((int *)&DAT_0034179c,0xf);
    FUN_002a1f60(piVar1,2);
  }
}
