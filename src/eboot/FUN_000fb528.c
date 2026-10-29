/* HSTMATCH module=EBOOT.BIN start=0x000fb528 end=0x000fb544 symbol=FUN_000fb528 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/mode_screen.h"

/* The status object's flag byte, or 0 when there is no status object. */
u8 FUN_000fb528(ModeScreen *self)
{
  u8 flag;
  ModeStatusObj *status;
  
  status = self->core->status;
  flag = 0;
  if (status != 0) {
    flag = status->unkb0;
  }
  return flag;
}
