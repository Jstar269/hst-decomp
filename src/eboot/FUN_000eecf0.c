/* HSTMATCH module=EBOOT.BIN start=0x000eecf0 end=0x000eed4c symbol=FUN_000eecf0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/inp_panes.h"
#include "hst/scene.h"

extern Scene *DAT_003386b0;
extern void FUN_000ffb3c(PaneItem *, int);
extern void FUN_00103128(SlotPane *);

/* Per-frame update of the slot pane: its first two items follow a scene byte while the pane is not shown. */
void FUN_000eecf0(SlotPane *pane)
{
  u8 flag;

  if (pane->base.shown == '\0') {
    flag = DAT_003386b0->unk4c;
    FUN_000ffb3c(pane->item[0],flag);
    FUN_000ffb3c(pane->item[1],flag);
    FUN_00103128(pane);
  }
}
