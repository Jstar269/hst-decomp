/* HSTMATCH module=EBOOT.BIN start=0x001b8bfc end=0x001b8c54 symbol=FUN_001b8bfc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p1) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001b94f8();
extern u32 * FUN_001b9708();

/* Constructs an embedded list object: clears it, sets the cleared flag and the initial state value 9. */
int FUN_001b8bfc(int self)
{
  u32 range_out;
  int range_end;
  int range_cursor;
  
  FUN_001b9708((u32 *)self);
  *(u8 *)(self + 0xc) = 0;
  range_cursor = self + 4;
  range_end = *(int *)(self + 8);
  FUN_001b94f8(&range_out,(int *)self,&range_end,&range_cursor);
  *(u32 *)(self + 0x10) = 9;
  return self;
}
