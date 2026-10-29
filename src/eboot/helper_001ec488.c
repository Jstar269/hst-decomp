/* HSTMATCH module=EBOOT.BIN start=0x001ec488 end=0x001ec518 symbol=FUN_001ec488 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: used a positive-count fast path and the named address symbol; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/overlay_obj.h"

typedef struct GameState {
  char pad[0x3c];
  int mode; /* 0x3c */
} GameState;

extern GameState * DAT_003386b0;
extern u8 DAT_0034179c;
extern u32 FUN_001b1c44();
extern void FUN_001ec564();

/* Store the value; a positive value shows the overlay, otherwise hide it (with a cue unless the game is in mode 9 or 2). */
void FUN_001ec488(OverlayObj *self,int value,int play_cue)
{
  self->unk14 = value;
  if (value > 0) {
    FUN_001ec564(self,1,0);
  }
  else {
    if (((DAT_003386b0 == 0) ||
        ((DAT_003386b0->mode != 9 && (DAT_003386b0->mode != 2)))) &&
       (play_cue != 0)) {
      FUN_001b1c44(&DAT_0034179c,0xb);
    }
    FUN_001ec564(self,0,0);
  }
}
