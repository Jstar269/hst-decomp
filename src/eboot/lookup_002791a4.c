/* HSTMATCH module=EBOOT.BIN start=0x002791a4 end=0x0027920c symbol=FUN_002791a4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: grouped valid switch cases around the shared table lookup; readability pass; exact match verified; names and types await human review. */
#include "hst/mode_menu.h"

#define CURSOR_NONE 4 /* GetCursor result for an invalid mode */

extern char DAT_002fe5e8[]; /* "Error, GetCursor(%d)\n" */
extern void FUN_0026f7f4();

/* Cursor of `mode` (1..4) minus CURSOR_NONE. */
int FUN_002791a4(ModeMenu *self, int mode)
{
  int value;
  switch (mode) {
    case 1:
    case 2:
    case 3:
    case 4: {
      value = self->cursor[mode - 1];
      break;
    }
    default:
      FUN_0026f7f4(DAT_002fe5e8);
      value = CURSOR_NONE;
      break;
  }
  return value - CURSOR_NONE;
}
