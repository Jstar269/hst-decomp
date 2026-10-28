/* HSTMATCH module=EBOOT.BIN start=0x001afa80 end=0x001afad8 symbol=FUN_001afa80 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: if/else order swapped (the flag-set branch first), typed pointers; readability pass; exact match verified; names and types await human review. */
#include "hst/game_state.h"

typedef struct Dispatcher {
  char pad00[8];
  int target; /* 0x08 passed on to the chosen handler */
} Dispatcher;

extern GameState *FUN_0019d474();
extern void FUN_001ab530(int, int);
extern void FUN_001abd8c(int, int);

void FUN_001afa80(Dispatcher *self, int arg)
{
  GameState *state = FUN_0019d474();
  if (state->unk3a1 != 0) {
    FUN_001abd8c(self->target, arg);
  }
  else {
    FUN_001ab530(self->target, arg);
  }
}
