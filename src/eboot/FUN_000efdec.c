/* HSTMATCH module=EBOOT.BIN start=0x000efdec end=0x000efe28 symbol=FUN_000efdec lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64b) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/pausable_obj.h"

extern void FUN_0005f1e8();
extern void FUN_001031e8();

void FUN_000efdec(PausableObj *self)
{
  if (self->disabled == 0) {
    FUN_001031e8();
    FUN_0005f1e8(self->unk90,self->unk9c);
  }
}
