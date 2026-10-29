/* HSTMATCH module=EBOOT.BIN start=0x001c9d7c end=0x001c9dec symbol=FUN_001c9d7c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

#define VALUE_COUNT 6

typedef struct Entry {
  char pad0[0x1b4];
  int unk1b4; /* 0x1b4 copied into the object, -1 for a missing entry */
} Entry;

typedef struct EntryTable {
  char pad0[0x50];
  Entry *entries[VALUE_COUNT]; /* 0x50 */
} EntryTable;

typedef struct ValueHolder {
  char pad0[0x134];
  int values[VALUE_COUNT]; /* 0x134 */
} ValueHolder;

extern EntryTable *DAT_0034a118;
extern char DAT_0034a678;
extern void FUN_00234158();

/* Copies one word per slot out of six global entries into the object. */
void FUN_001c9d7c(ValueHolder *obj)
{
  unsigned int i;
  Entry *e;
  int v;

  FUN_00234158(&DAT_0034a678, 0x24);
  i = 0;
  do {
    e = DAT_0034a118->entries[i];
    v = e ? e->unk1b4 : -1;
    obj->values[i] = v;
    i++;
  } while (i < VALUE_COUNT);
}
