/* HSTMATCH module=EBOOT.BIN start=0x001aa9a8 end=0x001aaab0 symbol=FUN_001aa9a8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/entry_panel.h"

extern void FUN_000ffb3c(EntrySprite *, int);
extern EntryMgr *FUN_0019d474(void);

/* Shows the two sprites of an entry row, hiding them again when the entry is switched off. */
void FUN_001aa9a8(EntryPanel *panel, int idx, int selector)
{
  EntryItem *first = &panel->items[selector + 8];
  EntryItem *second = &panel->items[selector + 9];
  int marked = 0;
  EntryMgr *mgr = FUN_0019d474();
  int rec_index = idx * 3; /* record idx, 0x30 bytes each */
  EntryRec *recs = mgr->recs;
  if (((EntryRec *)((char *)recs + (rec_index << 4)))->unka != 0)
    marked = 1;
  FUN_000ffb3c(first->spr, 1);
  FUN_000ffb3c(second->spr, 1);
  mgr = FUN_0019d474();
  if ((mgr->unk2a4 != 0) &&
      (mgr = FUN_0019d474(), mgr->flags->unk14[idx] == 0)) {
    FUN_000ffb3c(first->spr, 0);
    FUN_000ffb3c(second->spr, 0);
  }
  if (marked != 0)
    FUN_000ffb3c(second->spr, 0);
}
