/* HSTMATCH module=EBOOT.BIN start=0x001cc830 end=0x001cc880 symbol=FUN_001cc830 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/name_box_owner.h"

extern u32 DAT_0033b574;
extern void FUN_001cc8e8();
extern char FUN_002869cc();

/* Hands the second name buffer to a global service, then clears it. */
void FUN_001cc830(NameBoxOwner *self)
{
  FUN_002869cc(DAT_0033b574 + 0x1320,self->nameB,1);
  self->nameB[0] = 0;
  *(u8 *)(self->panel->unk20 + 0x6d) = 0;
  FUN_001cc8e8(self);
}
