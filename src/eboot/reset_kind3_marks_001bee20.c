/* HSTMATCH module=EBOOT.BIN start=0x001bee20 end=0x001bef18 symbol=FUN_001bee20 lang=c99 */
/* Hand-written reconstruction from the disassembly (EBOOT twin of src/sharing_main/reset_kind3_marks_001ccb74.c); exact match verified; names and types await human review. */
#include "hst/flag_tables.h"

extern int DAT_00338b08;
extern MgrEntry *FUN_000d8c24(int, int, int);
extern int FUN_001bb944(FlagTables *, int, int);
extern void FUN_001bf9b8(FlagTables *, int, int);

/* Clear the mark byte of each of the 640 kind-3 entries; mark entries that exist (all when `all` is set, index 0, state 1, or accepted by FUN_001bb944). */
void FUN_001bee20(FlagTables *self, int all)
{
  int i;
  for (i = 0; i < MARK_COUNT; i++) {
    MgrEntry *entry = FUN_000d8c24(DAT_00338b08, 3, i);
    self->marks3[i] = 0;
    if (entry != 0 && entry->state >= 0) {
      if (all != 0) {
        FUN_001bf9b8(self, i, 5);
      } else if (i == 0) {
        FUN_001bf9b8(self, i, 5);
      } else if (entry->state == 1) {
        FUN_001bf9b8(self, i, 5);
      } else if (FUN_001bb944(self, 3, i) != 0) {
        FUN_001bf9b8(self, i, 5);
      }
    }
  }
}
