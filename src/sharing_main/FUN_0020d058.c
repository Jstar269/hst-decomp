/* HSTMATCH module=hstp_trans_main.prx start=0x0020d058 end=0x0020d090 symbol=FUN_0020d058 lang=c99 */
/* Clone of src/eboot/FUN_001fe888.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/key_record.h"

/* Counts the records whose key is not the empty marker. */
int FUN_0020d058(KeyRecord *table)
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
