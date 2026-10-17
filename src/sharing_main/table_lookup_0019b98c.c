/* HSTMATCH module=hstp_trans_main.prx start=0x0019b98c end=0x0019ba18 symbol=FUN_0019b98c lang=c99 */
/* Clone of src/eboot/table_lookup_0018f1ac.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly (candidate hstgen.py a1/v0 restructured with structs; row offset written as i * 12 + (int)rows via a local); exact match verified; names and types await human review. */
extern char DAT_002d10cc;
extern char DAT_002d10d0;
extern char DAT_002d10d4;

typedef struct Row { void **items; int count; int pad; } Row;
typedef struct Tbl { int a; int b; int count; } Tbl;
typedef struct Obj { int x; int ok; Tbl *tbl; Row *rows; } Obj;

void *FUN_0019b98c(Obj *o, int i, int j)
{
  Row *r; int off;
  void *res;
  if (o->ok == 0) {
    res = &DAT_002d10d4;
  } else if (i < 0 || i >= o->tbl->count) {
    res = &DAT_002d10d0;
  } else if (j < 0 || (off = i * 12, r = (Row *)(off + (int)o->rows), j >= r->count)) {
    res = &DAT_002d10cc;
  } else {
    res = r->items[j];
  }
  return res;
}
