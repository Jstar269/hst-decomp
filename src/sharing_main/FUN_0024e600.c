/* HSTMATCH module=hstp_trans_main.prx start=0x0024e600 end=0x0024e614 symbol=FUN_0024e600 lang=c99 */
/* Clone of src/eboot/FUN_0023e468.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mode_host.h"

extern void FUN_0024e004();

/* Clears the control record's word and refreshes the host. */
void FUN_0024e600(ModeHost *host)
{
  host->ctl->unk1c = 0;
  FUN_0024e004(host,1,0);
}
