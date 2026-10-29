/* HSTMATCH module=EBOOT.BIN start=0x001bebb0 end=0x001bec74 symbol=FUN_001bebb0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/flag_tables.h"

extern int DAT_00338b08;
extern MgrEntry *FUN_000d8c24(int, int, u32);
extern void FUN_001bf884(FlagTables *, int, u8);

/* Clear the mark pair of each of the 640 kind-5 entries; mark entries that exist (all of them when `all` is set, else those with state 1). */
void FUN_001bebb0(FlagTables *self, int all)
{
  int i;
  for (i = 0; i < MARK_COUNT; i++) {
    MarkPair *pair = &self->pairs[i];
    MgrEntry *entry = FUN_000d8c24(DAT_00338b08, 5, i);
    pair->a = 0;
    pair->b = 0;
    if (entry != 0 && entry->state >= 0) {
      if (all != 0) {
        FUN_001bf884(self, i, 4);
      } else {
        if (entry->state == 1) {
          FUN_001bf884(self, i, 4);
        }
      }
    }
  }
}
