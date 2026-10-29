/* HSTMATCH module=hstp_trans_main.prx start=0x0017be40 end=0x0017be94 symbol=FUN_0017be40 lang=c99 */
/* Clone of src/eboot/FUN_0016fbf4.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/table_page.h"

extern void FUN_0017788c();
extern void FUN_0017cef0();
extern void FUN_0017d068();

/* Calls the page hook and two helpers on the page's handles. */
void FUN_0017be40(TablePage *self)
{
  self->hook(self->unkb8);
  FUN_0017788c(self->unkbc);
  FUN_0017cef0(self,0);
  if (self->unk3e != '\0') {
    FUN_0017d068(self);
  }
}
