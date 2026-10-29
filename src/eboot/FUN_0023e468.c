/* HSTMATCH module=EBOOT.BIN start=0x0023e468 end=0x0023e47c symbol=FUN_0023e468 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mode_host.h"

extern void FUN_0023de6c();

/* Clears the control record's word and refreshes the host. */
void FUN_0023e468(ModeHost *host)
{
  host->ctl->unk1c = 0;
  FUN_0023de6c(host,1,0);
}
