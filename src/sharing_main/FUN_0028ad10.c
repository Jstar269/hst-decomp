/* HSTMATCH module=hstp_trans_main.prx start=0x0028ad10 end=0x0028ae08 symbol=FUN_0028ad10 lang=c99 */
/* Clone of src/eboot/FUN_00279a2c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mode_menu.h"

extern char DAT_003a6f24[];
extern char DAT_003a6f58[];
extern char DAT_003a6f64[];
extern void FUN_00105470();
extern int FUN_00108124();
extern int FUN_00109304();

/* Shows one of the two assign panes depending on the sub cursor. */
void FUN_0028ad10(ModeMenu *self)
{
  u32 pane;
  
  if (self->sub->cursor < 4) {
    pane = FUN_00109304(self->widgets,DAT_003a6f24,0);
    pane = FUN_00108124(pane,DAT_003a6f58);
    FUN_00105470(pane,1);
    pane = FUN_00109304(self->widgets,DAT_003a6f24,0);
    pane = FUN_00108124(pane,DAT_003a6f64);
    FUN_00105470(pane,0);
  }
  else {
    pane = FUN_00109304(self->widgets,DAT_003a6f24,0);
    pane = FUN_00108124(pane,DAT_003a6f58);
    FUN_00105470(pane,0);
    pane = FUN_00109304(self->widgets,DAT_003a6f24,0);
    pane = FUN_00108124(pane,DAT_003a6f64);
    FUN_00105470(pane,1);
  }
}
