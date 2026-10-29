/* HSTMATCH module=hstp_trans_main.prx start=0x000f54b4 end=0x000f54f0 symbol=FUN_000f54b4 lang=c99 */
/* Clone of src/eboot/FUN_000efdec.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/pausable_obj.h"

extern void FUN_0005ffd8();
extern void FUN_00108aec();

void FUN_000f54b4(PausableObj *self)
{
  if (self->disabled == 0) {
    FUN_00108aec();
    FUN_0005ffd8(self->unk90,self->unk9c);
  }
}
