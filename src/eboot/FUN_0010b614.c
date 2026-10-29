/* HSTMATCH module=EBOOT.BIN start=0x0010b614 end=0x0010b684 symbol=FUN_0010b614 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mode_list.h"

extern void FUN_0010b150();
extern void FUN_0010b368();

/* Reset the list (keep_position = 1), load the first two halfwords of the current record, refresh the shown items. */
void FUN_0010b614(ModeList *self)
{
  FUN_0010b368(self,1);
  self->unkec = *(short *)((char *)self->recs + self->cur * 0xc);
  self->unkee = *(short *)((char *)self->recs + self->cur * 0xc + 2);
  FUN_0010b150(self);
  return;
}
