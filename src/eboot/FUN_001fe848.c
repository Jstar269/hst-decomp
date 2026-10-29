/* HSTMATCH module=EBOOT.BIN start=0x001fe848 end=0x001fe888 symbol=FUN_001fe848 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/key_record.h"

/* Returns 1 when a record with this key exists at or after index start. */
u32 FUN_001fe848(KeyRecord *table,int key,int start)
{
  KeyRecord *rec;
  
  if (start < KEY_RECORD_COUNT) {
    rec = table + start;
    do {
      if (key == rec->key) {
        return 1;
      }
      start = start + 1;
      rec = rec + 1;
    } while (start < KEY_RECORD_COUNT);
  }
  return 0;
}
