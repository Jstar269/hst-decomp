/* HSTMATCH module=EBOOT.BIN start=0x00115b78 end=0x00115bac symbol=FUN_00115b78 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00101f48();

typedef struct Obj_00115b78 {
  char pad00[0x908];
  u16 unk908; /* 0x908 */
} Obj_00115b78;

/* Runs the base action, then stores the 16-bit value. */
void FUN_00115b78(Obj_00115b78 *self,u16 value)
{
  FUN_00101f48();
  self->unk908 = value;
}
