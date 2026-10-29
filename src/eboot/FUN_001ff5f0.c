/* HSTMATCH module=EBOOT.BIN start=0x001ff5f0 end=0x001ff668 symbol=FUN_001ff5f0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: used a switch over the mode values to retain the retail reversed test order and branch delay stores; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
extern u32 DAT_0034a0fc; /* current mode, 1..4 */

/* Map the current mode to an index: valid is set to 1 for modes 1..4 and index receives 2, 1, 0 or 3. */
void FUN_001ff5f0(u8 *valid, int *index)
{
  *valid = 0;
  switch (DAT_0034a0fc) {
  case 1:
    *valid = 1;
    *index = 2;
    break;
  case 2:
    *valid = 1;
    *index = 1;
    break;
  case 3:
    *valid = 1;
    *index = 0;
    break;
  case 4:
    *valid = 1;
    *index = 3;
    break;
  default:
    break;
  }
}
