/* HSTMATCH module=EBOOT.BIN start=0x000e99d4 end=0x000e9a1c symbol=FUN_000e99d4 lang=c++ */
/* Hand-written reconstruction from the disassembly (delete of a member through its virtual destructor); exact match verified; names and types await human review. */
#include "hst/elem_owner.h"

/* Delete the owned member (if any) and clear the pointer. */
extern "C" void FUN_000e99d4(ElemOwner *self)
{
  MemberObj *member = self->member;
  if (member != 0) {
    delete member;
    self->member = 0;
  }
}
