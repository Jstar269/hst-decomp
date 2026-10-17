/* HSTMATCH module=EBOOT.BIN start=0x0027977c end=0x002797e8 symbol=FUN_0027977c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
extern char DAT_002fe674[];
extern void FUN_0026f7f4();

typedef struct Obj {
  char pad0[0x104];
  int mode;
  char pad1[0x10];
  int f118[4];
  int f128[4];
  int f138[4];
  int f148[4];
} Obj;

int FUN_0027977c(Obj *o)
{
  int mode = o->mode;
  switch (mode) {
  case 1:
  case 2:
  case 3:
  case 4:
    return o->f148[mode - 1];
  default:
    FUN_0026f7f4(DAT_002fe674, mode);
    return 0;
  }
}
