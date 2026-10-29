/* HSTMATCH module=EBOOT.BIN start=0x002a23d8 end=0x002a2434 symbol=FUN_002a23d8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/letter_host.h"

extern u8 DAT_0034179c;
extern int FUN_001b1c44();
extern void FUN_002a1f60();

/* When the panel is in state 1, calls FUN_001b1c44 and moves the panel to state 2. */
void FUN_002a23d8(LetterHost *host)
{
  LetterPanelRef *panel;
  
  if ((host->unk1b0 == 5) && (panel = host->panel, panel->state == 1)) {
    FUN_001b1c44((int *)&DAT_0034179c,0xf);
    FUN_002a1f60(panel,2);
  }
}
