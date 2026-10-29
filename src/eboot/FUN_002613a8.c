/* HSTMATCH module=EBOOT.BIN start=0x002613a8 end=0x0026141c symbol=FUN_002613a8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/entry_records.h"

/* Sets the entry's tail fields and its default UTF-8 name (13 bytes, ends in 'P'). */
void FUN_002613a8(Entry *entry)
{
  entry->unkc8 = 0;
  entry->unkec = 5.0f;
  entry->unkf0 = 10;
  entry->unkf1 = 0;
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
  return;
}
