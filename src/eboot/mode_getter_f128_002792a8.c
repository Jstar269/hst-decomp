/* HSTMATCH module=EBOOT.BIN start=0x002792a8 end=0x00279314 symbol=FUN_002792a8 lang=c99 data=0x002fe614 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002fe614-0x002fe62d) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
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

int FUN_002792a8(Obj *o)
{
  int mode = o->mode;
  switch (mode) {
  case 1:
  case 2:
  case 3:
  case 4:
    return o->f128[mode - 1];
  default:
    FUN_0026f7f4("Error, GetCursorOld(%d)\n", mode);
    return 4;
  }
}
