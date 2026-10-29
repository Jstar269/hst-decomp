/* HSTMATCH module=EBOOT.BIN start=0x002793b0 end=0x00279578 symbol=FUN_002793b0 lang=c99 helpers=FUN_0026f7f4@0x0026f7f4-0x0026f820 */
/* Hand-written reconstruction from the disassembly (lane ag4 near miss wip/menu_navigate_002793b0.cpp rewritten in C with the same-file static log stub FUN_0026f7f4 defined in front of it and placed at its own retail address by helpers=; the retail out-of-line siblings 0x00279380, 0x00279138 and 0x0027920c are inlined); exact match verified; names and types await human review. */
#include "hst/mode_menu.h"

extern char DAT_002fe5e8[]; /* "Error, GetCursor(%d)\n" */
extern char DAT_002fe600[]; /* "SetCursor(%d)=%d\n" */
extern char DAT_0034179c[];
extern void FUN_0010b8cc(void *, int, int);
extern int FUN_001b1c44(void *, int);

#define MODE_COUNT 4
#define CURSOR_NONE 4 /* GetCursor result for an invalid mode */

static void FUN_0026f7f4(...)
{
}

/* retail out of line at 0x00279380 */
static inline int SubCursorValid(ModeMenu *o)
{
  int c = o->sub->cursor;
  if (c >= 0 && c < MODE_COUNT)
    return 1;
  return 0;
}

/* retail out of line at 0x00279138 */
static inline int GetCursor(ModeMenu *o)
{
  int mode = o->mode;
  switch (mode) {
  case 1:
  case 2:
  case 3:
  case 4:
    return o->cursor[mode - 1];
  default:
    FUN_0026f7f4(DAT_002fe5e8, mode);
    return CURSOR_NONE;
  }
}

/* retail out of line at 0x0027920c */
static inline void UpdateCursor(ModeMenu *o, int key)
{
  int mode = o->mode;
  switch (mode) {
  case 1:
  case 2:
  case 3:
  case 4:
    FUN_0010b8cc(o->sub, key, 0);
    o->cursor[mode - 1] = o->sub->cursor;
    FUN_0026f7f4(DAT_002fe600, mode, o->cursor[mode - 1]);
    break;
  }
}

/* Moves the cursor for `key`; plays the cursor sound (FUN_001b1c44) when it changed. */
void FUN_002793b0(ModeMenu *self, int key)
{
  int cur = self->sub->cursor;
  int old;
  if (SubCursorValid(self)) {
    FUN_0010b8cc(self->sub, key, 0);
    if (cur != self->sub->cursor)
      FUN_001b1c44(DAT_0034179c, 1);
  } else {
    old = GetCursor(self);
    UpdateCursor(self, key);
    if (old != GetCursor(self))
      FUN_001b1c44(DAT_0034179c, 1);
  }
}
