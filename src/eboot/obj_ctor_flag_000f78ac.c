/* HSTMATCH module=EBOOT.BIN start=0x000f78ac end=0x000f7950 symbol=FUN_000f78ac lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0c) corrected by hand: the if/else flag store is a single store of a bool local (r = DAT == 0x2a; if (r) r = f() != 0), callee returns int; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/member_owner.h"

extern u8 DAT_0030777c;
extern u32 DAT_0034a678;
extern u32 * FUN_00102e38();
extern int FUN_0022c860();

/* Constructor: base init, vtable, clears the owned members and sets the flag at 0x156. */
MemberOwner * FUN_000f78ac(MemberOwner *self)
{
  int r;
  
  FUN_00102e38();
  self->vtable = &DAT_0030777c;
  self->members[0] = 0;
  self->members[1] = 0;
  self->members[2] = 0;
  self->members[3] = 0;
  self->members[4] = 0;
  self->members[5] = 0;
  self->members[6] = 0;
  self->members[7] = 0;
  self->members[8] = 0;
  self->members[9] = 0;
  self->members[10] = 0;
  self->members[11] = 0;
  self->members[12] = 0;
  self->members[13] = 0;
  self->members[14] = 0;
  self->members[15] = 0;
  self->members[16] = 0;
  self->members[17] = 0;
  r = DAT_0034a678 == 0x2a;
  if (r) {
    r = FUN_0022c860() != 0;
  }
  self->unk156 = r;
  return self;
}
