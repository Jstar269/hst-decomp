/* HSTMATCH module=EBOOT.BIN start=0x002933fc end=0x0029343c symbol=FUN_002933fc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64b) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/ctl_obj.h"

/* True while the object is active, unk40 is clear and the level has not passed CTL_LEVEL_MAX. */
u32 FUN_002933fc(CtlObj *ctl)
{
  u32 result;
  
  result = 0;
  if (((ctl->active != '\0') && (ctl->unk40 == '\0')) &&
     (ctl->level <= CTL_LEVEL_MAX)) {
    result = 1;
  }
  return result;
}
