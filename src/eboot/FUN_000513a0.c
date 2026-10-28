/* HSTMATCH module=EBOOT.BIN start=0x000513a0 end=0x000513e4 symbol=FUN_000513a0 lang=c99 */
/* Clone of src/sharing_main/FUN_00051d40.c (hstclone.py tag u4r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: expressed the three stores as ascending switch cases; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_000513a0(int param_1,int param_2)
{
  switch (param_2) {
    case 0: *(u32 *)(param_1 + 0x1c) = 0x10; break;
    case 1: *(u32 *)(param_1 + 0x1c) = 0x11; break;
    case 2: *(u32 *)(param_1 + 0x1c) = 0x12; break;
  }
}
