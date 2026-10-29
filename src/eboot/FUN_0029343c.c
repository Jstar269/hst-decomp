/* HSTMATCH module=EBOOT.BIN start=0x0029343c end=0x00293488 symbol=FUN_0029343c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/komono_obj.h"

extern char DAT_00309dec;
extern void * FUN_00286790();

/* Constructor: base init, then clears the owned pointers and the target. */
KomonoObj * FUN_0029343c(KomonoObj *obj)
{
  FUN_00286790();
  obj->vtable = &DAT_00309dec;
  obj->stream = 0;
  obj->unk74 = 0;
  obj->sub = 0;
  obj->target = 0;
  obj->unk80 = -1;
  return obj;
}
