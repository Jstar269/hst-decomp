/* HSTMATCH module=hstp_trans_main.prx start=0x002b0e58 end=0x002b0e70 symbol=FUN_002b0e58 lang=c99 */
/* Clone of src/eboot/FUN_002a1a4c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/anim_host.h"

/* Initialises the entry block with its id and clears the rest. */
void FUN_002b0e58(EntryBlock *block,u32 id)
{
  block->id = id;
  block->flag = 0;
  block->unk104 = 0;
  block->unk108 = 0;
  block->unk10c = 0;
}
