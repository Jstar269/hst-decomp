/* HSTMATCH module=EBOOT.BIN start=0x001fe888 end=0x001fe8c0 symbol=FUN_001fe888 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/key_record.h"

/* Counts the records whose key is not the empty marker. */
int FUN_001fe888(KeyRecord *table)
{
  int used;
  int i;
  
  used = 0;
  i = 0;
  do {
    if (table->key != KEY_RECORD_EMPTY) {
      used = used + 1;
    }
    i = i + 1;
    table = table + 1;
  } while (i < KEY_RECORD_COUNT);
  return used;
}
