/* HSTMATCH module=EBOOT.BIN start=0x00279380 end=0x002793b0 symbol=FUN_00279380 lang=c99 */
/* Hand-written reconstruction from the disassembly (the predicate inlined into 0x002793b0); exact match verified; names and types await human review. */
typedef struct Sub {
  char pad0[0xdc];
  int cursor;
} Sub;

typedef struct Obj {
  char pad0[0x474];
  Sub *sub;
} Obj;

int FUN_00279380(Obj *o)
{
  int c = o->sub->cursor;
  if (c >= 0 && c < 4)
    return 1;
  return 0;
}
