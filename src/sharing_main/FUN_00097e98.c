/* HSTMATCH module=hstp_trans_main.prx start=0x00097e98 end=0x00097eac symbol=FUN_00097e98 lang=c99 */
/* Clone of src/eboot/FUN_00095d94.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

/* Constructor: first byte cleared, second byte set to 0xff (none). */
s8 * FUN_00097e98(s8 *self)
{
  self[0] = 0;
  self[1] = 0xff;
  return self;
}
