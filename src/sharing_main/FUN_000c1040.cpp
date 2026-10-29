/* HSTMATCH module=hstp_trans_main.prx start=0x000c1040 end=0x000c1090 symbol=FUN_000c1040 lang=c++ */
/* Clone of src/eboot/FUN_000bdac4.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/member_host.h"

/* Deletes the owned object at the end of the host (if any) and clears the pointer. */
extern "C" void FUN_000c1040(MemberHost *self)
{
  OwnedObj *obj;
  
  obj = self->obj26c;
  if ((obj != 0) && (obj != 0)) {
    delete obj;
    self->obj26c = 0;
  }
}
