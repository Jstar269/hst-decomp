/* HSTMATCH module=hstp_trans_main.prx start=0x002bc4e4 end=0x002bc51c symbol=FUN_002bc4e4 lang=c99 */
/* Clone of src/eboot/FUN_002acd28.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

#define FLAG_TABLE_SIZE 0x28 /* entries of the flag table */

extern u8 DAT_002dc5b8[];

/* Looks up index in the flag table; an index outside the table reads as false. */
bool FUN_002bc4e4(int index)
{
  bool is_set;
  
  if (index >= 0 && (index < FLAG_TABLE_SIZE)) {
    is_set = DAT_002dc5b8[index] != '\0';
  }
  else {
    is_set = false;
  }
  return is_set;
}
