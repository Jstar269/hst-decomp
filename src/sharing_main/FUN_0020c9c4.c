/* HSTMATCH module=hstp_trans_main.prx start=0x0020c9c4 end=0x0020ca14 symbol=FUN_0020c9c4 lang=c99 */
/* Clone of src/eboot/FUN_001fe1f4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/key_record.h"

/* Marks every record in the table as empty. */
void FUN_0020c9c4(KeyRecord *table)
{
  int i;
  
  i = 0;
  do {
    table->key = KEY_RECORD_EMPTY;
    table->bytes[0] = 0;
    table->bytes[1] = 0;
    table->bytes[2] = 0;
    table->bytes[3] = 0;
    table->words[0] = KEY_RECORD_EMPTY;
    table->words[1] = KEY_RECORD_EMPTY;
    table->words[2] = KEY_RECORD_EMPTY;
    table->words[3] = KEY_RECORD_EMPTY;
    table->words[4] = KEY_RECORD_EMPTY;
    i = i + 1;
    table->words[5] = KEY_RECORD_EMPTY;
    table = table + 1;
  } while (i < KEY_RECORD_COUNT);
}
