/* HSTMATCH module=EBOOT.BIN start=0x001b9d10 end=0x001b9d78 symbol=FUN_001b9d10 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: C++ virtual deleting-destructor call on the member (vptr at +4 via a 4-byte non-polymorphic base), typed global pointers; readability pass; exact match verified; names and types await human review. */
#include "hst/owned_member_obj.h"

struct VB_0 { int x; };
struct VC_0 : VB_0 { virtual ~VC_0(); };
struct Cell { char pad0[0xc]; int unkc; char pad10[0x52 - 0x10]; char unk52; };
extern Cell *DAT_00331b84;
extern Cell *DAT_00331b88;

/* Delete and clear the owned member, then clear a field pair in each of the two global cells. */
extern "C" void FUN_001b9d10(OwnedMemberObj *self)
{
  VC_0 *m = (VC_0 *)self->member;
  if (m != 0) {
    delete m;
    self->member = 0;
  }
  Cell *a = DAT_00331b84;
  a->unkc = 0;
  a->unk52 = 0;
  Cell *b = DAT_00331b88;
  b->unkc = 0;
  b->unk52 = 0;
}
