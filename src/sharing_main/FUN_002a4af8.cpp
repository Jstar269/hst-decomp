/* HSTMATCH module=hstp_trans_main.prx start=0x002a4af8 end=0x002a4b70 symbol=FUN_002a4af8 lang=c++ */
/* Clone of src/eboot/FUN_002934ec.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/komono_obj.h"

extern "C" {
extern int FUN_000541d8(...);
extern int FUN_000569f4(...);
}
struct VC_0 { virtual ~VC_0(); };

/* Releases the owned sub-object, +0x74 object and stream. */
extern "C" void FUN_002a4af8(KomonoObj *obj)
{
  void *owned;
  
  owned = obj->sub;
  if (owned != (void *)0x0) {
    delete ((VC_0 *)(owned));
    obj->sub = 0;
  }
  owned = obj->unk74;
  if (owned != 0) {
    FUN_000569f4(owned,1);
    obj->unk74 = 0;
  }
  owned = obj->stream;
  if (owned != 0) {
    FUN_000541d8(owned,1);
    obj->stream = 0;
  }
}
