/* HSTMATCH module=EBOOT.BIN start=0x001ca8f0 end=0x001ca92c symbol=FUN_001ca8f0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_001ca92c();
extern u32 * FUN_0022a744();
extern int FUN_0022a930();

enum { ITEM_ARRAY_OFFSET = 0xa210 }; /* start of the item record array inside the object returned by the accessor */

/* Build a record in a local buffer and pass it, with the item array, to the helper. */
void FUN_001ca8f0(void)
{
  char *world;
  u32 *record;
  u32 buffer[1172];

  world = (char *)(FUN_0022a930());
  record = FUN_0022a744(buffer);
  FUN_001ca92c((u32 *)(world + ITEM_ARRAY_OFFSET),record);
}
