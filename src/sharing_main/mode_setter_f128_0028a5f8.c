/* HSTMATCH module=hstp_trans_main.prx start=0x0028a5f8 end=0x0028a664 symbol=FUN_0028a5f8 lang=c99 helpers=FUN_00280834@0x00280834-0x00280860 */
/* Hand-written reconstruction from the disassembly (port of the matched EBOOT twin src/eboot/mode_setter_f128_00279314.c; the same-file static log stub FUN_00280834 is defined in front of it and placed at its own retail address by helpers=); exact match verified; names and types await human review. */
extern char DAT_003a7358[];
static void FUN_00280834(...)
{
}

typedef struct Obj {
  char pad0[0x104];
  int mode;
  char pad1[0x10];
  int f118[4];
  int f128[4];
  int f138[4];
  int f148[4];
} Obj;

void FUN_0028a5f8(Obj *o, int value)
{
  int mode = o->mode;
  switch (mode) {
  case 1:
  case 2:
  case 3:
  case 4:
    o->f128[mode - 1] = value;
    FUN_00280834(DAT_003a7358, mode, value);
    break;
  }
}
