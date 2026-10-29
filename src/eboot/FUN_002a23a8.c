/* HSTMATCH module=EBOOT.BIN start=0x002a23a8 end=0x002a23d8 symbol=FUN_002a23a8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/letter_host.h"

extern void FUN_002a1f60();

/* Sets the panel to state 0. */
void FUN_002a23a8(LetterHost *host)
{
  if (host->unk1b0 == 5) {
    FUN_002a1f60(host->panel,0);
  }
}
