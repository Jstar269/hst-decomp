/* HSTMATCH module=EBOOT.BIN start=0x0013fb50 end=0x0013fb58 symbol=FUN_0013fb50 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

#define THIS_ADJUST 0x40 /* distance from this sub-object to the start of the full object */

extern u32 * FUN_001323e8(u32 *param_1,short param_2);

/* Thunk: moves the pointer back to the full object and forwards to its deleting destructor. */
void FUN_0013fb50(char *self,short delete_flag)
{
  FUN_001323e8((u32 *)(self - THIS_ADJUST),delete_flag);
}
