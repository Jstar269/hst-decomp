/* HSTMATCH module=EBOOT.BIN start=0x00279648 end=0x002796b4 symbol=FUN_00279648 lang=c99 helpers=FUN_0026f7f4@0x0026f7f4-0x0026f820 */
/* Hand-written reconstruction from the disassembly (lane sw1 near miss wip/mode_setter_f138_00279648.c, completed with its same-file static helper FUN_0026f7f4 defined in front of it and placed at its own retail address by helpers=); exact match verified; names and types await human review. */
extern char DAT_002fe660[];
static void FUN_0026f7f4(...)
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

void FUN_00279648(Obj *o, int value)
{
  int mode = o->mode;
  switch (mode) {
  case 1:
  case 2:
  case 3:
  case 4:
    o->f138[mode - 1] = value;
    FUN_0026f7f4(DAT_002fe660, mode, value);
    break;
  }
}
