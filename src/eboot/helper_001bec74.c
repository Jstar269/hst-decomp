/* HSTMATCH module=EBOOT.BIN start=0x001bec74 end=0x001bed48 symbol=FUN_001bec74 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: used a direct signed-byte guard and the retail nested likely-branch ordering; readability pass; exact match verified; names and types await human review. */
#include "hst/flag_tables.h"

extern u32 DAT_00338b08;
extern MgrEntry *FUN_000d8c24();
extern u32 FUN_001bb944();
extern void FUN_001bf948();

/* Clear the mark byte of each of the 640 kind-1 entries; mark entries that exist (all when `all` is set, state 1, or accepted by FUN_001bb944). */
void FUN_001bec74(FlagTables *self,int all)
{
  MgrEntry *entry;
  int i;
  
  i = 0;
  do {
    entry = FUN_000d8c24(DAT_00338b08,1,i);
    self->marks1[i] = 0;
    if (entry != 0 && entry->state >= 0) {
      if (all != 0) {
        FUN_001bf948(self,i,5);
      }
      else if (entry->state == 1) {
        FUN_001bf948(self,i,5);
      }
      else {
        if (FUN_001bb944(self,1,i) != 0) {
          FUN_001bf948(self,i,5);
        }
      }
    }
    i = i + 1;
  } while (i < MARK_COUNT);
}
