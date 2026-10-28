/* HSTMATCH module=EBOOT.BIN start=0x0008d6cc end=0x0008d72c symbol=FUN_0008d6cc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128b) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/entry_records.h"

extern int FUN_00000788(void *, void *, int, int);
extern void FUN_00000a00(void *);
extern void FUN_0008d4e0();

/* EntryTable deleting destructor: destroys the Entry array, frees the object when flags > 0. */
EntryTable *FUN_0008d6cc(EntryTable *table, short flags)
{
  if ((table != 0) && (FUN_00000788(table->entries, FUN_0008d4e0, sizeof(Entry), ENTRY_TABLE_COUNT), 0 < flags)) {
    FUN_00000a00(table);
  }
  return table;
}
