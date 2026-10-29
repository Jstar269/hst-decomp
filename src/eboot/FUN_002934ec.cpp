/* HSTMATCH module=EBOOT.BIN start=0x002934ec end=0x00293564 symbol=FUN_002934ec lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/komono_obj.h"

extern "C" {
extern int FUN_00053718(...);
extern int FUN_00055e48(...);
}
struct VC_0 { virtual ~VC_0(); };

/* Releases the owned sub-object, +0x74 object and stream. */
extern "C" void FUN_002934ec(KomonoObj *obj)
{
  void *owned;
  
  owned = obj->sub;
  if (owned != (void *)0x0) {
    delete ((VC_0 *)(owned));
    obj->sub = 0;
  }
  owned = obj->unk74;
  if (owned != 0) {
    FUN_00055e48(owned,1);
    obj->unk74 = 0;
  }
  owned = obj->stream;
  if (owned != 0) {
    FUN_00053718(owned,1);
    obj->stream = 0;
  }
}
