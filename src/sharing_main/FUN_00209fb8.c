/* HSTMATCH module=hstp_trans_main.prx start=0x00209fb8 end=0x00209fc8 symbol=FUN_00209fb8 lang=c99 */
/* Clone of src/eboot/FUN_001fb8a0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/slot_panel.h"

/* Increments the record counter. */
void FUN_00209fb8(PanelRec *rec)
{
  rec->unke0 = rec->unke0 + 1;
}
