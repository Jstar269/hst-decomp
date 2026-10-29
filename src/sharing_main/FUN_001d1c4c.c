/* HSTMATCH module=hstp_trans_main.prx start=0x001d1c4c end=0x001d1c6c symbol=FUN_001d1c4c lang=c99 */
/* Clone of src/eboot/FUN_001c38c0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/menu_state.h"

/* Set the flag at 0x61; turning it on also sets the flag at 0x62. */
void FUN_001d1c4c(MenuState *self,u8 flag)
{
  self->unk61 = flag;
  if (self->unk61 != '\0') {
    self->unk62 = 1;
  }
}
