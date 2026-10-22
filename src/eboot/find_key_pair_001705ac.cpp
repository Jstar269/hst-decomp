/* HSTMATCH module=EBOOT.BIN start=0x001705ac end=0x00170658 symbol=FUN_001705ac lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: the two count fields are volatile so their loads are re-evaluated at the bottom of each loop like retail. */
#pragma opt_strength_reduction off
struct Entry { int **data; volatile unsigned count; int pad; };
struct Obj { int f0; unsigned f4; unsigned f8; int fC; int f10; int f14; Entry *list; volatile unsigned count; };

extern "C" void FUN_001705ac(int unused, Obj *o, int key)
{
  unsigned foundInner = 0x7fffffff;
  unsigned foundOuter = 0x7fffffff;
  for (unsigned outer = 0; outer < o->count; outer++) {
    Entry *e = (Entry *)((char *)o->list + outer * 12);
    for (unsigned inner = 0; inner < e->count; inner++) {
      if (key == *e->data[inner]) {
        foundInner = inner;
        foundOuter = outer;
        goto found;
      }
    }
  }
found:
  if (foundInner != 0x7fffffff && foundOuter != 0x7fffffff) {
    o->f4 = foundInner;
    o->f8 = foundOuter;
  }
}
