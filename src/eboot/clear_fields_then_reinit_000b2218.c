/* HSTMATCH module=EBOOT.BIN start=0x000b2218 end=0x000b228c symbol=FUN_000b2218 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: the 11-argument callee prototype interleaves its floats among the ints (float, 5 ints, float, 3 ints, float) which reproduces retail argument-setup order; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/chara_player.h"

extern void FUN_000b237c(float, CharaPlayer *, int, int, int, int, float, int, int, int, float);
extern u32 FUN_000b3390();

/* If the guard passes, clear six state words and restart the player's motion with the default arguments. */
void FUN_000b2218(CharaPlayer *self)
{
  int ok;
  
  ok = FUN_000b3390(self);
  if (ok != 0) {
    self->unk444 = 0;
    self->unk448 = 0;
    self->unk44c = 0;
    self->unk450 = 0;
    self->unk454 = 0;
    self->unk458 = 0;
    FUN_000b237c(0.0f,self,0,1,1,1,0.0f,1,0,0,0.0f);
  }
}
