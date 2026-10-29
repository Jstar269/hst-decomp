/* HSTMATCH module=EBOOT.BIN start=0x0018a950 end=0x0018a960 symbol=FUN_0018a950 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/phase_screen.h"

extern void FUN_0010d4a8();

/* Show `buffer` in the first text box and refresh it. */
void FUN_0018a950(PhaseScreen *self,void *buffer)
{
  TextBox *box;
  
  box = self->boxes[0];
  box->buffer = buffer;
  box->unk138 = 0;
  FUN_0010d4a8(box);
}
