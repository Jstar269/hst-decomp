/* HSTMATCH module=EBOOT.BIN start=0x000fb7b8 end=0x000fb810 symbol=FUN_000fb7b8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. matching idiom: a shared `goto ret0` (equivalently one || chain plus a shared exit) reproduces retail's beql(x==9)/beq(x==2) chain and single shared return-0 block. */
#include "hst/mode_screen.h"
#include "hst/game_mode_state.h"

extern GameModeState * DAT_003386b0;

#define LIMIT_BLOCKS 10 /* a limits value above this blocks the request */

/* Nonzero when the request is allowed: not in mode 9 or 2, and the limit is not exceeded. */
u32 FUN_000fb7b8(ModeScreen *self)
{
  int mode;
  ModeCore *core;

  if (DAT_003386b0 != 0) {
    mode = DAT_003386b0->mode;
    if (mode == 9 || mode == 2) {
      goto ret0;
    }
  }
  core = self->core;
  if (LIMIT_BLOCKS < core->limits->unkc) {
    goto ret0;
  }
  return 1;
ret0:
  return 0;
}
