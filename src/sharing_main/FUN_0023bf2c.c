/* HSTMATCH module=hstp_trans_main.prx start=0x0023bf2c end=0x0023bf58 symbol=FUN_0023bf2c lang=c99 */
/* Clone of src/eboot/FUN_0022c4ac.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_003ea8e8;  /* address of the global system block */

/* Stores a pair of words in the system block. */
void FUN_0023bf2c(u32 first,u32 second)
{
  *(u32 *)(DAT_003ea8e8 + 0xe020) = first;
  *(u32 *)(DAT_003ea8e8 + 0xe024) = second;
}
