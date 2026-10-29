/* HSTMATCH module=EBOOT.BIN start=0x00259fbc end=0x00259ffc symbol=FUN_00259fbc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/spawn_owner.h"

extern u32 DAT_003417c4;
extern void FUN_001b4dfc();
extern void FUN_00255674();
extern int FUN_00285c78();

/* Feeds the owner's handle, converted by a lookup, to the update helper for its sub-object. */
void FUN_00259fbc(SpawnOwner *owner)
{
  u32 value;
  
  FUN_001b4dfc(DAT_003417c4);
  value = FUN_00285c78(owner->handle);
  FUN_00255674(owner->sub,value);
}
