/* HSTMATCH module=EBOOT.BIN start=0x001cc784 end=0x001cc7d0 symbol=FUN_001cc784 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/name_box_owner.h"

extern u32 * FUN_000149a8();
extern int FUN_00014a40();

/* Sets the first name buffer when `name` fits. */
void FUN_001cc784(NameBoxOwner *self,u32 name)
{
  u32 length;
  
  length = FUN_00014a40(name);
  if (length < NAME_BOX_NAME_LIMIT) {
    FUN_000149a8(self->nameA,name);
  }
}
