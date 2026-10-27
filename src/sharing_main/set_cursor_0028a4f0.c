/* HSTMATCH module=hstp_trans_main.prx start=0x0028a4f0 end=0x0028a580 symbol=FUN_0028a4f0 lang=c99 helpers=FUN_00280834@0x00280834-0x00280860 */
/* Hand-written reconstruction from the disassembly ("SetCursor(%d)=%d\n" log; the same-file static log stub FUN_00280834 is defined in front of it and placed at its own retail address by helpers=, which gives retail's v1/a3 temporaries and the store in the stub's jal delay slot); exact match verified; names and types await human review. */
extern char DAT_003a7328[];
static void FUN_00280834(...)
{
}

typedef struct Cursor {
  char pad0[0xdc];
  int pos;
} Cursor;

extern void FUN_00111aa4(Cursor *, int, int);

typedef struct Obj {
  char pad0[0x104];
  int mode;
  char pad1[0xc];
  int f114[5];
  char pad2[0x474 - 0x128];
  Cursor *cursor;
} Obj;

void FUN_0028a4f0(Obj *o, int pos)
{
  int mode = o->mode;
  switch (mode) {
  case 1:
  case 2:
  case 3:
  case 4:
    FUN_00111aa4(o->cursor, pos, 0);
    o->f114[mode] = o->cursor->pos;
    FUN_00280834(DAT_003a7328, mode, o->f114[mode]);
    break;
  }
}
