/* HSTMATCH module=hstp_trans_main.prx start=0x001ccb74 end=0x001ccc6c symbol=FUN_001ccb74 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/flag_tables.h"

extern int DAT_003e1e48;
extern MgrEntry *FUN_000dca74(int, int, int);
extern int FUN_001c972c(FlagTables *, int, int);
extern void FUN_001cd7f8(FlagTables *, int, int);

/* Clear the mark byte of each of the 640 kind-3 entries; mark entries that exist (all when `all` is set, index 0, state 1, or accepted by FUN_001c972c). */
void FUN_001ccb74(FlagTables *self, int all)
{
  int i;
  for (i = 0; i < MARK_COUNT; i++) {
    MgrEntry *entry = FUN_000dca74(DAT_003e1e48, 3, i);
    self->marks3[i] = 0;
    if (entry != 0 && entry->state >= 0) {
      if (all != 0) {
        FUN_001cd7f8(self, i, 5);
      } else if (i == 0) {
        FUN_001cd7f8(self, i, 5);
      } else if (entry->state == 1) {
        FUN_001cd7f8(self, i, 5);
      } else if (FUN_001c972c(self, 3, i) != 0) {
        FUN_001cd7f8(self, i, 5);
      }
    }
  }
}
