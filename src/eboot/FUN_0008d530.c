/* HSTMATCH module=EBOOT.BIN start=0x0008d530 end=0x0008d640 symbol=FUN_0008d530 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s512a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/entry_records.h"

extern void FUN_000114c0(void *, int, int);
extern void FUN_0008d640(void *, int, int);
extern void FUN_0008d650(void *);
extern void FUN_000d7e70(void *);

/* Entry constructor (array-constructed by the table constructor). */
Entry *FUN_0008d530(Entry *entry)
{
  FUN_0008d650(entry);
  FUN_000114c0(entry, 0, sizeof(Rec200));
  FUN_0008d640(entry, 0, 0);
  FUN_0008d640(entry, 1, 0);
  FUN_0008d640(entry, 2, 0);
  FUN_0008d640(entry, 3, 0);
  FUN_0008d640(entry, 4, 0);
  FUN_0008d640(entry, 5, 0);
  FUN_000d7e70(entry);
  entry->unkc8 = 0;
  entry->unkec = 5.0f;
  entry->unkf0 = 10;
  entry->unkf1 = 0;
  /* default UTF-8 string, five characters (four 3-byte kana, then 'P') */
  entry->strc9[0] = 0xe3;
  entry->strc9[1] = 0x81;
  entry->strc9[2] = 0xbf;
  entry->strc9[3] = 0xe3;
  entry->strc9[4] = 0x82;
  entry->strc9[5] = 0x93;
  entry->strc9[6] = 0xe3;
  entry->strc9[7] = 0x83;
  entry->strc9[8] = 0x86;
  entry->strc9[9] = 0xe3;
  entry->strc9[10] = 0x83;
  entry->strc9[11] = 0x8b;
  entry->strc9[12] = 0x50;
  return entry;
}
