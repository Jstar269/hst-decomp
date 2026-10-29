/* HSTMATCH module=EBOOT.BIN start=0x000eee60 end=0x000eee98 symbol=FUN_000eee60 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/inp_panes.h"

extern void FUN_000eeec8(SmallPane *);
extern void FUN_001036f8(SmallPane *, int);

/* Clears the small pane's two trailing words, hides it, then runs FUN_001036f8. */
void FUN_000eee60(SmallPane *pane)
{
  pane->unk6c = 0;
  pane->unk70 = 0;
  FUN_000eeec8(pane);
  FUN_001036f8(pane,0);
}
