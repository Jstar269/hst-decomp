/* HSTMATCH module=hstp_trans_main.prx start=0x0008ebd0 end=0x0008ec34 symbol=FUN_0008ebd0 lang=c99 */
/* Clone of src/eboot/FUN_0008d47c.c (hstclone.py tag x11): addresses substituted; exact match verified; names and types await human review. */
#include "hst/entry_records.h"

extern void FUN_000007f4(void *, void *, void *, int, int);
extern void FUN_000114c0(void *, int, int);
extern void FUN_0008ec34();
extern void FUN_0008ec84();

/* EntryTable constructor: array-constructs the four Entries, then clears the trailing Rec6c. */
EntryTable *FUN_0008ebd0(EntryTable *table)
{
  FUN_000007f4(table->entries, FUN_0008ec84, FUN_0008ec34, sizeof(Entry), ENTRY_TABLE_COUNT);
  FUN_000114c0(&table->info, 0, sizeof(Rec6c));
  table->info.unk68 = REC_ID_NONE;
  table->info.unk6a = REC_ID_NONE;
  table->info.unk24 = REC_ID_NONE;
  return table;
}
