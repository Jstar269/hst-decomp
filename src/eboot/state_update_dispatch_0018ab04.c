/* HSTMATCH module=EBOOT.BIN start=0x0018ab04 end=0x0018abec symbol=FUN_0018ab04 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: the if/else-if chain on the state rewritten as a switch with cases 0..4 in source order (empty case 4); readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/phase_screen.h"

#define PAD_BUTTON_CONFIRM 0x4000 /* button mask polled for the confirm press */

enum {
  PHASE_BLEND_IN = 0,
  PHASE_2 = 1,
  PHASE_3 = 2,
  PHASE_4 = 3,
  PHASE_IDLE = 4
};

extern u32 DAT_002cfc8c;
extern u8 FUN_0001eb44();
extern void FUN_000ffb3c();
extern void FUN_00103128();
extern void FUN_00103480();
extern void FUN_0018abec();
extern void FUN_0018ad0c();
extern void FUN_0018b1d0();
extern void FUN_0018b2bc();

/* Per-frame update: show/hide the widget, poll the confirm button, run the current phase. */
void FUN_0018ab04(PhaseScreen *self)
{
  u8 pressed;
  int phase;
  u32 show;
  
  show = (u32)(self->phase != PHASE_3);
  if (show == 0) {
    show = (u32)(0 < self->unk60);
  }
  FUN_000ffb3c(self->unk74,show);
  pressed = FUN_0001eb44(DAT_002cfc8c,self->input,PAD_BUTTON_CONFIRM);
  self->confirm = pressed;
  phase = self->phase;
  switch (phase) {
  case PHASE_BLEND_IN:
    FUN_0018abec(self);
    break;
  case PHASE_2:
    FUN_0018ad0c(self);
    break;
  case PHASE_3:
    FUN_0018b1d0(self);
    break;
  case PHASE_4:
    FUN_0018b2bc(self);
    break;
  case PHASE_IDLE:
    break;
  }
  FUN_00103480(self);
  FUN_00103128(self);
}
