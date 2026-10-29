/* HSTMATCH module=EBOOT.BIN start=0x0027b8c4 end=0x0027b8cc symbol=FUN_0027b8c4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

#define BASE_OFFSET 0x3c /* the embedded object sits this far into the full object */

extern u32 * FUN_0026ce14(u32 *base,short flag);

/* Thunk: forward to the base-class function with the pointer adjusted back by BASE_OFFSET. */
void FUN_0027b8c4(u8 *self,short flag)
{
  FUN_0026ce14((u32 *)(self - BASE_OFFSET),flag);
}
