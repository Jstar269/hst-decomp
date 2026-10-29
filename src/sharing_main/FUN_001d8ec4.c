/* HSTMATCH module=hstp_trans_main.prx start=0x001d8ec4 end=0x001d8f00 symbol=FUN_001d8ec4 lang=c99 */
/* Clone of src/eboot/FUN_001ca8f0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_001d8f00();
extern u32 * FUN_00239cb8();
extern int FUN_00239ea4();

enum { ITEM_ARRAY_OFFSET = 0xa210 }; /* start of the item record array inside the object returned by the accessor */

/* Build a record in a local buffer and pass it, with the item array, to the helper. */
void FUN_001d8ec4(void)
{
  char *world;
  u32 *record;
  u32 buffer[1172];

  world = (char *)(FUN_00239ea4());
  record = FUN_00239cb8(buffer);
  FUN_001d8f00((u32 *)(world + ITEM_ARRAY_OFFSET),record);
}
