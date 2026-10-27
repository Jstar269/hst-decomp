/* HSTMATCH module=hstp_trans_main.prx start=0x0028aacc end=0x0028ab38 symbol=FUN_0028aacc lang=c99 helpers=FUN_00280834@0x00280834-0x00280860 */
/* Hand-written reconstruction from the disassembly (adapted from the exact EBOOT twin src/eboot/mode_setter_f148_002797e8.c: addresses substituted, the same-file static log stub FUN_00280834 defined in front of it and placed at its own retail address by helpers=, the four per-mode arrays named after the module's log strings); exact match verified; names and types await human review. */
/* SetScrollOld: stores the value for the current mode (1..4) and logs "SetScrollOld(%d)=%d".
   The neighbouring log strings (Get/SetCursor, Get/SetCursorOld, Get/SetScroll, Get/SetScrollOld)
   name the four 4-entry arrays at 0x118, 0x128, 0x138 and 0x148. */
extern char DAT_003a73b8[];

static void FUN_00280834(...)
{
}

typedef struct Obj {
  char pad0[0x104];
  int mode;
  char pad1[0x10];
  int cursor[4];
  int cursor_old[4];
  int scroll[4];
  int scroll_old[4];
} Obj;

void FUN_0028aacc(Obj *o, int value)
{
  int mode = o->mode;
  switch (mode) {
  case 1:
  case 2:
  case 3:
  case 4:
    o->scroll_old[mode - 1] = value;
    FUN_00280834(DAT_003a73b8, mode, value);
    break;
  }
}
