/* HSTMATCH module=EBOOT.BIN start=0x002acd28 end=0x002acd60 symbol=FUN_002acd28 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

#define FLAG_TABLE_SIZE 0x28 /* entries of the flag table */

extern u8 DAT_002cc2cc[];

/* Looks up index in the flag table; an index outside the table reads as false. */
bool FUN_002acd28(int index)
{
  bool is_set;
  
  if (index >= 0 && (index < FLAG_TABLE_SIZE)) {
    is_set = DAT_002cc2cc[index] != '\0';
  }
  else {
    is_set = false;
  }
  return is_set;
}
