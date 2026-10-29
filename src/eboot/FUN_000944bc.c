/* HSTMATCH module=EBOOT.BIN start=0x000944bc end=0x000944c8 symbol=FUN_000944bc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe1) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/bone_link.h"

/* Sets the two bone names. */
void FUN_000944bc(BoneLink *self,const char *name_a,const char *name_b)
{
  self->nameA = name_a;
  self->nameB = name_b;
}
