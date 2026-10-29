/* HSTMATCH module=EBOOT.BIN start=0x00279a2c end=0x00279b24 symbol=FUN_00279a2c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mode_menu.h"

extern char DAT_002fe240[];
extern char DAT_002fe274[];
extern char DAT_002fe280[];
extern void FUN_000ffb3c();
extern int FUN_001026b8();
extern int FUN_001039d8();

/* Shows one of the two assign panes depending on the sub cursor. */
void FUN_00279a2c(ModeMenu *self)
{
  u32 pane;
  
  if (self->sub->cursor < 4) {
    pane = FUN_001039d8(self->widgets,DAT_002fe240,0);
    pane = FUN_001026b8(pane,DAT_002fe274);
    FUN_000ffb3c(pane,1);
    pane = FUN_001039d8(self->widgets,DAT_002fe240,0);
    pane = FUN_001026b8(pane,DAT_002fe280);
    FUN_000ffb3c(pane,0);
  }
  else {
    pane = FUN_001039d8(self->widgets,DAT_002fe240,0);
    pane = FUN_001026b8(pane,DAT_002fe274);
    FUN_000ffb3c(pane,0);
    pane = FUN_001039d8(self->widgets,DAT_002fe240,0);
    pane = FUN_001026b8(pane,DAT_002fe280);
    FUN_000ffb3c(pane,1);
  }
}
