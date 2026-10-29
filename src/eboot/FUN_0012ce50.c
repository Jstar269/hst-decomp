/* HSTMATCH module=EBOOT.BIN start=0x0012ce50 end=0x0012cea0 symbol=FUN_0012ce50 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003313c4;
extern u32 DAT_00338714;
extern int FUN_0005ba78();
extern void FUN_00140acc();
extern void FUN_00145c5c();

/* Teardown step: passes the registry to the object registered in DAT_00338714 (if any), then runs the two cleanup calls. */
void FUN_0012ce50(u32 obj)
{
  if (DAT_00338714 != 0) {
    FUN_0005ba78(DAT_00338714,DAT_003313c4);
  }
  FUN_00140acc(obj);
  FUN_00145c5c(obj);
}
