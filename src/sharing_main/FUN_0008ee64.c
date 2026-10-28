/* HSTMATCH module=hstp_trans_main.prx start=0x0008ee64 end=0x0008eec4 symbol=FUN_0008ee64 lang=c99 */
/* Clone of src/eboot/FUN_0008d6cc.c (hstclone.py tag x11): addresses substituted; exact match verified; names and types await human review. */
#include "hst/entry_records.h"

extern int FUN_00000788(void *, void *, int, int);
extern void FUN_00000a00(void *);
extern void FUN_0008ec34();

/* EntryTable deleting destructor: destroys the Entry array, frees the object when flags > 0. */
EntryTable *FUN_0008ee64(EntryTable *table, short flags)
{
  if ((table != 0) && (FUN_00000788(table->entries, FUN_0008ec34, sizeof(Entry), ENTRY_TABLE_COUNT), 0 < flags)) {
    FUN_00000a00(table);
  }
  return table;
}
