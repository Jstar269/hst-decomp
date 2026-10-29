/* HSTMATCH module=EBOOT.BIN start=0x001fb404 end=0x001fb44c symbol=FUN_001fb404 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_panel.h"

extern u8 DAT_0034179c;
extern int FUN_001b1c44();

/* Acquires the panel's handle if it has none (handle == -1) and clears its countdown. */
void FUN_001fb404(SlotPanel *panel)
{
  int handle;
  
  if (panel->handle == -1) {
    handle = FUN_001b1c44((int *)&DAT_0034179c,0x10);
    panel->handle = handle;
    panel->count = 0;
  }
}
