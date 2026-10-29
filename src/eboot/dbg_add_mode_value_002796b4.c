/* HSTMATCH module=EBOOT.BIN start=0x002796b4 end=0x0027977c symbol=FUN_002796b4 lang=c99 helpers=FUN_0026f7f4@0x0026f7f4-0x0026f820 */
/* Hand-written reconstruction from the disassembly (near miss wip/dbg_add_mode_value_002796b4.c, completed with its same-file static helper FUN_0026f7f4 defined in front of it and placed at its own retail address by helpers=); exact match verified; names and types await human review. */
#include "hst/mode_menu.h"

extern char DAT_002fe648[]; /* "Error, GetScroll(%d)\n" */
extern char DAT_002fe660[]; /* "SetScroll(%d)=%d\n" */
static void FUN_0026f7f4(...) {}

static inline int GetScroll(ModeMenu *o)
{
  int m = o->mode;
  switch (m) {
  case 1:
  case 2:
  case 3:
  case 4:
    return o->scroll[m - 1];
  default:
    FUN_0026f7f4(DAT_002fe648, m);
    return 0;
  }
}

static inline void SetScroll(ModeMenu *o, int val)
{
  int m = o->mode;
  switch (m) {
  case 1:
  case 2:
  case 3:
  case 4:
    o->scroll[m - 1] = val;
    FUN_0026f7f4(DAT_002fe660, m, val);
    break;
  }
}

/* Adds `delta` to the active mode's scroll value. */
void FUN_002796b4(ModeMenu *self, int delta)
{
  SetScroll(self, delta + GetScroll(self));
}
