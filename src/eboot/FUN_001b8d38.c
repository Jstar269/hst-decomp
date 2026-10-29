/* HSTMATCH module=EBOOT.BIN start=0x001b8d38 end=0x001b8da8 symbol=FUN_001b8d38 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0c) corrected by hand: kept `this` in its own local (s1) and the +0x3c sub-object in a second (s0) so the object survives the calls, passed `this` as the base constructor argument, sub-object access as pointer arithmetic; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003092c0;
extern void FUN_0001f06c();
extern u32 *FUN_001b9708();
extern void FUN_001b94f8();

/* Constructor: base-class init, then the embedded list at +0x3c, then the vtable pointer. */
u32 *FUN_001b8d38(u32 *param_1)
{
  u8 range_out[4];
  u32 range_end;
  u32 *range_cursor;
  u32 *self = param_1;
  u32 *list;

  FUN_0001f06c(self);
  list = self + 0xf;
  FUN_001b9708(list);
  ((u8 *)list)[12] = 0;
  range_cursor = list + 1;
  range_end = list[2];
  FUN_001b94f8(range_out, list, &range_end, &range_cursor);
  *self = (unsigned int)(&DAT_003092c0);
  return self;
}
