/* HSTMATCH module=EBOOT.BIN start=0x0010b684 end=0x0010b6d4 symbol=FUN_0010b684 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mode_list.h"

extern void FUN_0010b150();
extern void FUN_0010b368();

/* Reset the list, then set its highlight mode and refresh the shown items. */
void FUN_0010b684(ModeList *self,u32 mode,u8 flag)
{
  FUN_0010b368(self,0);
  self->unk114 = flag;
  self->mode = mode;
  FUN_0010b150(self);
}
