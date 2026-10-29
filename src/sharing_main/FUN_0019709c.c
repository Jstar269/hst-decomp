/* HSTMATCH module=hstp_trans_main.prx start=0x0019709c end=0x001970ac symbol=FUN_0019709c lang=c99 */
/* Clone of src/eboot/FUN_0018a950.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/phase_screen.h"

extern void FUN_00113a50();

/* Show `buffer` in the first text box and refresh it. */
void FUN_0019709c(PhaseScreen *self,void *buffer)
{
  TextBox *box;
  
  box = self->boxes[0];
  box->buffer = buffer;
  box->unk138 = 0;
  FUN_00113a50(box);
}
