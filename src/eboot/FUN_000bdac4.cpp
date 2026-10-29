/* HSTMATCH module=EBOOT.BIN start=0x000bdac4 end=0x000bdb14 symbol=FUN_000bdac4 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/member_host.h"

/* Deletes the owned object at the end of the host (if any) and clears the pointer. */
extern "C" void FUN_000bdac4(MemberHost *self)
{
  OwnedObj *obj;
  
  obj = self->obj26c;
  if ((obj != 0) && (obj != 0)) {
    delete obj;
    self->obj26c = 0;
  }
}
