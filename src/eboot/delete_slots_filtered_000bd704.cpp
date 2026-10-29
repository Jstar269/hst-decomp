/* HSTMATCH module=EBOOT.BIN start=0x000bd704 end=0x000bd7a4 symbol=FUN_000bd704 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: loop index declared before the walking pointer (s-register order); readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/member_host.h"

/* Deletes the owned object of every member slot (or only slot `which`; a negative value means all). */
extern "C" void FUN_000bd704(MemberHost *self,int which)
{
  int i;
  OwnedObj *obj;
  
  i = 0;
  do {
    if ((self->slots[i] != 0) && ((which == i || (which < 0)))) {
      self->flags[i] = 0;
      obj = self->slots[i];
      if (obj != 0) {
        delete obj;
        self->slots[i] = 0;
      }
    }
    i = i + 1;
  } while (i < MEMBER_MAX);
}
