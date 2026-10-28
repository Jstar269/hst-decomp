/* HSTMATCH module=EBOOT.BIN start=0x001cd83c end=0x001cd88c symbol=FUN_001cd83c lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */

struct Obj {
  int f0;
  int f4;
  int f8;
  int fc;
  int f10;
};

extern "C" void FUN_001ce864(Obj *, int);

extern "C" void FUN_001cd83c(Obj *o)
{
  if (o->f4 != o->f10) {
    int c = o->fc - 1;
    o->fc = c;
    if (c < 1) {
      FUN_001ce864(o, o->f10);
      return;
    }
  }
  o->f8 = o->f8 + 1;
}
