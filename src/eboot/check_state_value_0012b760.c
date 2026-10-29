/* HSTMATCH module=EBOOT.BIN start=0x0012b760 end=0x0012b7cc symbol=FUN_0012b760 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: reordered the conditions and grouped the signed offset expression; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/avatar_obj.h"

extern u32 DAT_0033b4b0;
extern u32 DAT_0033b4b4;

struct AvatarSkel {
  char pad00[0xf0];
  int currentAnim;          /* 0xf0 */
};

/* Checks the skeleton's current animation against the avatar's selected one. */
bool FUN_0012b760(Avatar *self)
{
  bool playing;
  int playingAnim;
  
  if (self->skel == 0) {
    playing = false;
  }
  else {
    playingAnim = self->skel->currentAnim;
    playing = false;
    if (self->unk334 >= 0) {
      if (playingAnim == self->unk334) {
        playing = playingAnim <= (int)DAT_0033b4b4;
      }
    }
    else if (playingAnim == (int)DAT_0033b4b0 +
        (self->unk354 + (int)self->unk364 * 2)) {
      playing = true;
    }
  }
  return playing;
}
