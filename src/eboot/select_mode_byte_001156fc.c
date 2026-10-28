/* HSTMATCH module=EBOOT.BIN start=0x001156fc end=0x0011574c symbol=FUN_001156fc lang=c99 */
/* Clone of src/sharing_main/select_mode_byte_00120618.c (hstclone.py tag u4r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh128a) corrected by hand: rewrote the mode chain as ordered switch cases; exact match verified; names and types await human review. */
#include "hst/types.h"

u8 FUN_001156fc(int param_1)
{
  switch (*(int *)(param_1 + 0x68)) {
    case 1:
      return *(u8 *)(*(int *)(param_1 + 0x58) + 0x6c);
    case 2:
    case 5:
      return *(u8 *)(param_1 + 0x7c);
    case 6:
      return *(u8 *)(param_1 + 0x84);
    default:
      return 0;
  }
}
