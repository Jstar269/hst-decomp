/* HSTMATCH module=EBOOT.BIN start=0x0027920c end=0x0027929c symbol=FUN_0027920c lang=c99 helpers=FUN_0026f7f4@0x0026f7f4-0x0026f820 */
/* Hand-written reconstruction (port of src/sharing_main/set_cursor_0028a4f0.c, its twin: addresses substituted by try/twins-20261026/port.py; no other change); exact match verified; names and types await human review. */
extern char DAT_002fe600[];
static void FUN_0026f7f4(...)
{
}

typedef struct Cursor {
  char pad0[0xdc];
  int pos;
} Cursor;

extern void FUN_0010b8cc(Cursor *, int, int);

typedef struct Obj {
  char pad0[0x104];
  int mode;
  char pad1[0xc];
  int f114[5];
  char pad2[0x474 - 0x128];
  Cursor *cursor;
} Obj;

void FUN_0027920c(Obj *o, int pos)
{
  int mode = o->mode;
  switch (mode) {
  case 1:
  case 2:
  case 3:
  case 4:
    FUN_0010b8cc(o->cursor, pos, 0);
    o->f114[mode] = o->cursor->pos;
    FUN_0026f7f4(DAT_002fe600, mode, o->f114[mode]);
    break;
  }
}
