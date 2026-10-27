/* HSTMATCH module=hstp_trans_main.prx start=0x0028a694 end=0x0028a85c symbol=FUN_0028a694 lang=c99 helpers=FUN_00280834@0x00280834-0x00280860 */
/* Clone of src/eboot/menu_navigate_002793b0.c (hstclone.py tag c072907): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (lane ag4 near miss wip/menu_navigate_0028a694.cpp rewritten in C with the same-file static log stub FUN_00280834 defined in front of it and placed at its own retail address by helpers=; the retail out-of-line siblings 0x00279380, 0x00279138 and 0x0027920c are inlined); exact match verified; names and types await human review. */
extern char DAT_003a7310[]; /* "Error, GetCursor(%d)\n" */
extern char DAT_003a7328[]; /* "SetCursor(%d)=%d\n" */
extern char DAT_003eaad8[];
extern void FUN_00111aa4(void *, int, int);
extern int FUN_001bfc3c(void *, int);

static void FUN_00280834(...)
{
}

typedef struct Sub {
  char pad0[0xdc];
  int cursor;
} Sub;

typedef struct Obj {
  char pad0[0x104];
  int mode;
  char pad1[0x10];
  int f118[4];
  char pad2[0x474 - 0x128];
  Sub *sub;
} Obj;

/* retail out of line at 0x00279380 */
static inline int SubCursorValid(Obj *o)
{
  int c = o->sub->cursor;
  if (c >= 0 && c < 4)
    return 1;
  return 0;
}

/* retail out of line at 0x00279138 */
static inline int GetCursor(Obj *o)
{
  int mode = o->mode;
  switch (mode) {
  case 1:
  case 2:
  case 3:
  case 4:
    return o->f118[mode - 1];
  default:
    FUN_00280834(DAT_003a7310, mode);
    return 4;
  }
}

/* retail out of line at 0x0027920c */
static inline void UpdateCursor(Obj *o, int key)
{
  int mode = o->mode;
  switch (mode) {
  case 1:
  case 2:
  case 3:
  case 4:
    FUN_00111aa4(o->sub, key, 0);
    o->f118[mode - 1] = o->sub->cursor;
    FUN_00280834(DAT_003a7328, mode, o->f118[mode - 1]);
    break;
  }
}

void FUN_0028a694(Obj *self, int key)
{
  int cur = self->sub->cursor;
  int old;
  if (SubCursorValid(self)) {
    FUN_00111aa4(self->sub, key, 0);
    if (cur != self->sub->cursor)
      FUN_001bfc3c(DAT_003eaad8, 1);
  } else {
    old = GetCursor(self);
    UpdateCursor(self, key);
    if (old != GetCursor(self))
      FUN_001bfc3c(DAT_003eaad8, 1);
  }
}
