/* HSTMATCH module=EBOOT.BIN start=0x0029a9a0 end=0x0029aa6c symbol=FUN_0029a9a0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: preserve the allocation result and assign the initialized result through one shared field store; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/net_adhoc.h"

extern int FUN_00000bcc();
extern u32 * FUN_000ff4fc();

/* Resets a MatchState and allocates its 0x14-byte sub-object. */
MatchState * FUN_0029a9a0(MatchState *self)
{
  int mem;
  u32 obj;
  
  self->active = 0;
  self->unk4 = 0;
  self->ref = 0;
  self->handle = -1;
  self->unk10 = 0;
  self->unk14 = 1;
  self->unk15 = 1;
  self->unk16 = 0;
  self->unk17 = 0;
  self->unk18 = 0;
  self->obj1c = 0;
  self->unk7420 = 0;
  self->unke424 = 0;
  self->unk15828 = 0;
  self->unk1582c = 0;
  self->unk15830 = 0x7fffffff;
  self->unk15834 = 0;
  self->unk15838 = 0;
  mem = FUN_00000bcc(0x14);
  obj = mem;
  if (mem != 0)
    obj = (unsigned int)(FUN_000ff4fc(mem,0x40000));
  self->obj1c = (RefObj *)obj;
  return self;
}
