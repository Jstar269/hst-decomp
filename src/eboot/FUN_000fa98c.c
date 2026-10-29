/* HSTMATCH module=EBOOT.BIN start=0x000fa98c end=0x000fa9d4 symbol=FUN_000fa98c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/hud_scene.h"

/* Zero every entry and its gauge's fields, for each gauge that exists. */
void FUN_000fa98c(HudScene *gauge_base)
{
  u32 i;
  HudScene *entry_base; /* both cursors walk the scene: gauges by 4 bytes, entries by 12 */
  HudGauge *gauge;
  
  i = 0;
  entry_base = gauge_base;
  do {
    gauge = gauge_base->gauges[0];
    if (gauge != 0) {
      entry_base->entries[0].unk0 = 0;
      gauge->unk60 = 0;
      entry_base->entries[0].unk4 = 0;
      gauge->unk64 = 0;
      entry_base->entries[0].unk8 = 0;
      gauge->value = 0;
    }
    i = i + 1;
    gauge_base = (HudScene *)((char *)gauge_base + 4);
    entry_base = (HudScene *)((char *)entry_base + 0xc);
  } while (i < HUD_GAUGE_COUNT);
}
