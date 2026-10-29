/* HSTMATCH module=EBOOT.BIN start=0x001cb7d0 end=0x001cb860 symbol=FUN_001cb7d0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/panel_data.h"

extern u32 DAT_003415ac;
extern void FUN_0010b8cc();
extern void FUN_00114168();
extern void FUN_001c2498();
extern void FUN_001cd88c();
extern u8 * FUN_002294f4();

/* Looks up the entry for key in the panel's map and, when found, shows it and queues the next step. */
void FUN_001cb7d0(PanelOwner *owner,u32 key)
{
  u8 *entry;
  PanelData *panel;
  
  panel = owner->panel;
  panel->unkb0 = 0;
  entry = FUN_002294f4(panel->map34,panel->bank,key,0);
  if (entry != 0) {
    FUN_00114168(DAT_003415ac,1,entry,0,0);
    FUN_0010b8cc(**(u32 **)(DAT_003415ac + 0x58),0,0);
    FUN_001cd88c(panel,4,1);
    FUN_001c2498(panel);
  }
}
