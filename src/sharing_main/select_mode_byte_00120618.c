/* HSTMATCH module=hstp_trans_main.prx start=0x00120618 end=0x00120668 symbol=FUN_00120618 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh128a) corrected by hand: rewrote the mode chain as ordered switch cases; exact match verified; names and types await human review. */
#include "hst/types.h"

u8 FUN_00120618(int param_1)
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
