/* HSTMATCH module=EBOOT.BIN start=0x001afe6c end=0x001afef4 symbol=FUN_001afe6c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: typed object with a volatile state field read into a local before the table entry (retail loads it first), loop index declared before the walking pointer (s1/s0 order); readability pass; exact match verified; names and types await human review. */
#include "hst/slot_table.h"

extern int DAT_002e5970[];
extern int DAT_002e5978[3];
extern int DAT_002e5984[];
extern void FUN_001b04d0(SlotTable *, int);
extern void FUN_001b08a0(SlotTable *, int *, int);

void FUN_001afe6c(SlotTable *self)
{
  unsigned i;
  int *id; /* walks the 3-entry id table */
  FUN_001b08a0(self, DAT_002e5984, 2);
  FUN_001b08a0(self, DAT_002e5970, 2);
  for (i = 0, id = DAT_002e5978; i < 3; i++) {
    int c = self->cur;
    int v = *id;
    if (c != v) {
      FUN_001b04d0(self, v);
    }
    id++;
  }
}
