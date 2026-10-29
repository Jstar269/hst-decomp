/* HSTMATCH module=EBOOT.BIN start=0x00091828 end=0x00091830 symbol=FUN_00091828 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

#define BASE_THUNK_OFFSET 0x1e0 /* distance from this sub-object back to the full object */

extern u32 * FUN_0008df24(u32 *self,short deleteFlag);

/* Adjusting thunk: forwards to the full object's deleting destructor. */
void FUN_00091828(int subObject,short deleteFlag)
{
  FUN_0008df24((u32 *)((u32 *)(subObject + -BASE_THUNK_OFFSET)),(short)(deleteFlag));
}
