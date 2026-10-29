/* HSTMATCH module=EBOOT.BIN start=0x00238d74 end=0x00238db0 symbol=FUN_00238d74 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void *FUN_00000bcc();
extern u32 * FUN_00238db0();

/* Allocate a 0x1938-byte object and construct it with the given argument. */
void FUN_00238d74(u32 arg)
{
  void *obj;

  obj = FUN_00000bcc(0x1938);
  if (obj != 0) {
    FUN_00238db0(obj,arg);
  }
}
