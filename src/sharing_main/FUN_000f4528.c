/* HSTMATCH module=hstp_trans_main.prx start=0x000f4528 end=0x000f4560 symbol=FUN_000f4528 lang=c99 */
/* Clone of src/eboot/FUN_000eee60.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/inp_panes.h"

extern void FUN_000f4590(SmallPane *);
extern void FUN_00109024(SmallPane *, int);

/* Clears the small pane's two trailing words, hides it, then runs FUN_00109024. */
void FUN_000f4528(SmallPane *pane)
{
  pane->unk6c = 0;
  pane->unk70 = 0;
  FUN_000f4590(pane);
  FUN_00109024(pane,0);
}
