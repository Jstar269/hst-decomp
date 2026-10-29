/* HSTMATCH module=hstp_trans_main.prx start=0x00100c64 end=0x00100c80 symbol=FUN_00100c64 lang=c99 */
/* Clone of src/eboot/FUN_000fb528.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/mode_screen.h"

/* The status object's flag byte, or 0 when there is no status object. */
u8 FUN_00100c64(ModeScreen *self)
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
