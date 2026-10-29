/* HSTMATCH module=hstp_trans_main.prx start=0x00209b0c end=0x00209b1c symbol=FUN_00209b0c lang=c99 */
/* Clone of src/eboot/FUN_001fb3f4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/slot_panel.h"

/* Increments the panel counter. */
void FUN_00209b0c(SlotPanel *panel)
{
  panel->unk1034 = panel->unk1034 + 1;
}
