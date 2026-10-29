/* HSTMATCH module=hstp_trans_main.prx start=0x002b1770 end=0x002b17cc symbol=FUN_002b1770 lang=c99 */
/* Clone of src/eboot/FUN_002a23d8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/letter_host.h"

extern u8 DAT_003eaad8;
extern int FUN_001bfc3c();
extern void FUN_002b136c();

/* When the panel is in state 1, calls FUN_001bfc3c and moves the panel to state 2. */
void FUN_002b1770(LetterHost *host)
{
  LetterPanelRef *panel;
  
  if ((host->unk1b0 == 5) && (panel = host->panel, panel->state == 1)) {
    FUN_001bfc3c((int *)&DAT_003eaad8,0xf);
    FUN_002b136c(panel,2);
  }
}
