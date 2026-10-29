/* HSTMATCH module=EBOOT.BIN start=0x000ddc6c end=0x000ddca8 symbol=FUN_000ddc6c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/side_tally.h"

typedef struct DeltaObj {
  char pad00[0xc4];
  int delta_a;      /* 0xc4 */
  int delta_b;      /* 0xc8 */
} DeltaObj;

extern TallyOwner *DAT_003386b0;

/* Adds the object's two delta words to the tally's first two counters. */
void FUN_000ddc6c(DeltaObj *obj)
{
  DAT_003386b0->tally->unk54 = DAT_003386b0->tally->unk54 + obj->delta_a;
  DAT_003386b0->tally->unk58 = DAT_003386b0->tally->unk58 + obj->delta_b;
}
