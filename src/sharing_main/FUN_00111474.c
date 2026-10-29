/* HSTMATCH module=hstp_trans_main.prx start=0x00111474 end=0x001114d8 symbol=FUN_00111474 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p1) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mode_list.h"

/* Reset the cursor state; unless keep_position is set, also go back to the start record. */
void FUN_00111474(ModeList *self,int keep_position)
{
  u32 i;
  int *key;  /* walks the key words from the object start (they begin 0xf0 in) */
  
  self->unkd0 = 0;
  if (keep_position == 0) {
    self->cur = self->start;
    self->unke0 = 0;
    self->last = self->rec_count + -1;
  }
  self->unke8 = 0;
  self->unke9 = 0;
  self->unkea = 0;
  self->unkec = 0;
  self->unkee = 0;
  self->unk11c = 0;
  self->unk11e = 0;
  i = 0;
  key = (int *)self;
  do {
    i = i + 1;
    *(int *)((char *)key + 0xf0) = 0;
    key = key + 1;
  } while (i < MODE_LIST_KEY_WORDS);
  self->unk12c = 1;
}
