/* HSTMATCH module=EBOOT.BIN start=0x00293488 end=0x002934ec symbol=FUN_00293488 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/komono_obj.h"

extern char DAT_00309dec;
extern void FUN_00000a00();
extern void * FUN_0028686c();
extern void FUN_002934ec();

/* Deleting destructor. */
KomonoObj * FUN_00293488(KomonoObj *obj,short flags)
{
  if (obj != (KomonoObj *)0x0) {
    obj->vtable = &DAT_00309dec;
    FUN_002934ec();
    FUN_0028686c(obj,0);
    if (0 < flags) {
      FUN_00000a00(obj);
    }
  }
  return obj;
}
