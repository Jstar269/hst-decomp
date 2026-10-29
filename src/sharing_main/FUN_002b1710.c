/* HSTMATCH module=hstp_trans_main.prx start=0x002b1710 end=0x002b1740 symbol=FUN_002b1710 lang=c99 */
/* Clone of src/eboot/FUN_002a2378.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/letter_host.h"

extern void FUN_002b136c();

/* Sets the panel to state 1. */
void FUN_002b1710(LetterHost *host)
{
  if (host->unk1b0 == 5) {
    FUN_002b136c(host->panel,1);
  }
}
