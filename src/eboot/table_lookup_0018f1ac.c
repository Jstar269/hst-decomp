/* HSTMATCH module=EBOOT.BIN start=0x0018f1ac end=0x0018f238 symbol=FUN_0018f1ac lang=c99 */
/* Hand-written reconstruction from the disassembly (candidate hstgen.py a1/v0 restructured with structs; row offset written as i * 12 + (int)rows via a local); exact match verified; names and types await human review. */
extern char DAT_002c0e18;
extern char DAT_002c0e1c;
extern char DAT_002c0e20;

typedef struct Row { void **items; int count; int pad; } Row;
typedef struct Tbl { int a; int b; int count; } Tbl;
typedef struct Obj { int x; int ok; Tbl *tbl; Row *rows; } Obj;

void *FUN_0018f1ac(Obj *o, int i, int j)
{
  Row *r; int off;
  void *res;
  if (o->ok == 0) {
    res = &DAT_002c0e20;
  } else if (i < 0 || i >= o->tbl->count) {
    res = &DAT_002c0e1c;
  } else if (j < 0 || (off = i * 12, r = (Row *)(off + (int)o->rows), j >= r->count)) {
    res = &DAT_002c0e18;
  } else {
    res = r->items[j];
  }
  return res;
}
