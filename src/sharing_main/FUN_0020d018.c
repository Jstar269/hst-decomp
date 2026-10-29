/* HSTMATCH module=hstp_trans_main.prx start=0x0020d018 end=0x0020d058 symbol=FUN_0020d018 lang=c99 */
/* Clone of src/eboot/FUN_001fe848.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/key_record.h"

/* Returns 1 when a record with this key exists at or after index start. */
u32 FUN_0020d018(KeyRecord *table,int key,int start)
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
