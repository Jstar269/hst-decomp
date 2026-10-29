/* HSTMATCH module=EBOOT.BIN start=0x0017e9b0 end=0x0017e9c0 symbol=FUN_0017e9b0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/light_obj.h"

/* Restart the fade: progress back to zero and advancing. */
void FUN_0017e9b0(LightObj *light)
{
  light->active = 1;
  light->progress = 0.0f;
}
