/* HSTMATCH module=EBOOT.BIN start=0x001b9760 end=0x001b97a4 symbol=FUN_001b9760 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/owned_member_obj.h"

extern u8 DAT_003092f8;
extern u32 * FUN_0001f06c();

/* Constructor: base init, vtable, and the owned member and flags cleared. */
OwnedMemberObj * FUN_001b9760(OwnedMemberObj *self)
{
  FUN_0001f06c();
  self->vtable = (unsigned int)(&DAT_003092f8);
  self->member = 0;
  self->unk40 = 0;
  self->unk41 = 0;
  self->unk44 = 0;
  return self;
}
