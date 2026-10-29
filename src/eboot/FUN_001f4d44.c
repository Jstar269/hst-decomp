/* HSTMATCH module=EBOOT.BIN start=0x001f4d44 end=0x001f4df0 symbol=FUN_001f4d44 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag not recorded in lane candidate inputs/generated/FUN_001f4d44.c) corrected by hand: inverted the likely-branch field test and ordered the locals to match the loop counter and cursor registers; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_group.h"

extern u32 DAT_002c8f0c[];
extern UiHost *DAT_003386b0;
extern int FUN_001b5764();

/* For the selected slot that has something attached, report its entry from the table to the UI host. */
void FUN_001f4d44(SlotGroup *self)
{
  HostSub *host;
  int i;
  SlotGroup *cursor; /* walks the group base 4 bytes per slot */
  int attached;

  i = 0;
  host = DAT_003386b0->sub;
  cursor = self;
  do {
    if (cursor->slot[0] != 0) {
      attached = (int)cursor->slot[0]->attached;
    } else {
      attached = 0;
    }
    if (((attached != 0) && ((int)host != 0)) && (i == self->selected)) {
      FUN_001b5764(host,i,DAT_002c8f0c[self->mode]);
    }
    i = i + 1;
    cursor = (SlotGroup *)((char *)cursor + 4);
  } while (i < SLOT_GROUP_COUNT);
}
