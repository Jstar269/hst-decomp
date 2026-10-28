/* HSTMATCH module=EBOOT.BIN start=0x0008d47c end=0x0008d4e0 symbol=FUN_0008d47c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128b) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/entry_records.h"

extern void FUN_000007f4(void *, void *, void *, int, int);
extern void FUN_000114c0(void *, int, int);
extern void FUN_0008d4e0();
extern void FUN_0008d530();

/* EntryTable constructor: array-constructs the four Entries, then clears the trailing Rec6c. */
EntryTable *FUN_0008d47c(EntryTable *table)
{
  FUN_000007f4(table->entries, FUN_0008d530, FUN_0008d4e0, sizeof(Entry), ENTRY_TABLE_COUNT);
  FUN_000114c0(&table->info, 0, sizeof(Rec6c));
  table->info.unk68 = REC_ID_NONE;
  table->info.unk6a = REC_ID_NONE;
  table->info.unk24 = REC_ID_NONE;
  return table;
}
