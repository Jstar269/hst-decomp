/* HSTMATCH module=hstp_trans_main.prx start=0x0028a998 end=0x0028aa60 symbol=FUN_0028a998 lang=c99 helpers=FUN_00280834@0x00280834-0x00280860 */
/* Hand-written reconstruction from the disassembly (adapted from the exact EBOOT twin src/eboot/dbg_add_mode_value_002796b4.c: addresses substituted, the same-file static log stub FUN_00280834 defined in front of it and placed at its own retail address by helpers=, the getter and setter named after their log strings and indexing the scroll array by mode - 1); exact match verified; names and types await human review. */
/* Adds a delta to the scroll value of the current mode (1..4): the inlined GetScroll logs
   "Error, GetScroll(%d)" and yields 0 for any other mode, the inlined SetScroll stores and logs
   "SetScroll(%d)=%d". */
extern char DAT_003a7370[];
extern char DAT_003a7388[];

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

static inline int GetScroll(Obj *o)
{
  int mode = o->mode;
  switch (mode) {
  case 1:
  case 2:
  case 3:
  case 4:
    return o->scroll[mode - 1];
  default:
    FUN_00280834(DAT_003a7370, mode);
    return 0;
  }
}

static inline void SetScroll(Obj *o, int value)
{
  int mode = o->mode;
  switch (mode) {
  case 1:
  case 2:
  case 3:
  case 4:
    o->scroll[mode - 1] = value;
    FUN_00280834(DAT_003a7388, mode, value);
    break;
  }
}

void FUN_0028a998(Obj *o, int delta)
{
  SetScroll(o, delta + GetScroll(o));
}
