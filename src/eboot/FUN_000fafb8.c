/* HSTMATCH module=EBOOT.BIN start=0x000fafb8 end=0x000fafec symbol=FUN_000fafb8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/hud_scene.h"

typedef struct GameState {
  char pad[0x3c];
  int mode; /* 0x3c */
} GameState;

extern GameState *DAT_003386b0;
extern void FUN_000f9290();

void FUN_000fafb8(HudScene *self)
{
  if (DAT_003386b0->mode != 9) {
    FUN_000f9290(self->unk3c);
  }
}
