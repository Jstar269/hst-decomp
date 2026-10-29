/* HSTMATCH module=hstp_trans_main.prx start=0x00209b1c end=0x00209b64 symbol=FUN_00209b1c lang=c99 */
/* Clone of src/eboot/FUN_001fb404.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_panel.h"

extern u8 DAT_003eaad8;
extern int FUN_001bfc3c();

/* Acquires the panel's handle if it has none (handle == -1) and clears its countdown. */
void FUN_00209b1c(SlotPanel *panel)
{
  int handle;
  
  if (panel->handle == -1) {
    handle = FUN_001bfc3c((int *)&DAT_003eaad8,0x10);
    panel->handle = handle;
    panel->count = 0;
  }
}
