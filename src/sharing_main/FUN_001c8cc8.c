/* HSTMATCH module=hstp_trans_main.prx start=0x001c8cc8 end=0x001c8cf4 symbol=FUN_001c8cc8 lang=c99 */
/* Clone of src/eboot/FUN_001baf80.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

#define TABLE_BASE 0x5c /* start of the byte table inside the object FUN_001aa91c returns */

extern u32 FUN_001aa91c();

/* Byte `index` of the table in the singleton object. */
u8 FUN_001c8cc8(int index)
{
  int singleton;
  
  singleton = FUN_001aa91c();
  return *(u8 *)(index + singleton + TABLE_BASE);
}
