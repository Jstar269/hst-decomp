/* HSTMATCH module=hstp_trans_main.prx start=0x002a4a48 end=0x002a4a94 symbol=FUN_002a4a48 lang=c99 */
/* Clone of src/eboot/FUN_0029343c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/komono_obj.h"

extern char DAT_003b30d4;
extern void * FUN_00297ebc();

/* Constructor: base init, then clears the owned pointers and the target. */
KomonoObj * FUN_002a4a48(KomonoObj *obj)
{
  FUN_00297ebc();
  obj->vtable = &DAT_003b30d4;
  obj->stream = 0;
  obj->unk74 = 0;
  obj->sub = 0;
  obj->target = 0;
  obj->unk80 = -1;
  return obj;
}
