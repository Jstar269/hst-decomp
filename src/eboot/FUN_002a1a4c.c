/* HSTMATCH module=EBOOT.BIN start=0x002a1a4c end=0x002a1a64 symbol=FUN_002a1a4c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/anim_host.h"

/* Initialises the entry block with its id and clears the rest. */
void FUN_002a1a4c(EntryBlock *block,u32 id)
{
  block->id = id;
  block->flag = 0;
  block->unk104 = 0;
  block->unk108 = 0;
  block->unk10c = 0;
}
