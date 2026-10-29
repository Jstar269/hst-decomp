/* HSTMATCH module=EBOOT.BIN start=0x001fc4e8 end=0x001fc5b8 symbol=FUN_001fc4e8 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/part_holder.h"

extern "C" {
}
struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };
struct VC_2 { virtual ~VC_2(); };
struct VC_3 { virtual ~VC_3(); };

/* Delete the owned parts (A only when deleteA is set) and clear their pointers. */
extern "C" void FUN_001fc4e8(PartHolder *self,int deleteA)
{
  PartD *d;
  PartC *c;
  PartB *b;
  PartA *a;

  d = self->partD;
  if (d != (PartD *)0x0) {
    delete ((VC_0 *)(d));
    self->partD = 0;
  }
  c = self->partC;
  if (c != (PartC *)0x0) {
    delete ((VC_1 *)(c));
    self->partC = 0;
  }
  b = self->partB;
  if (b != (PartB *)0x0) {
    delete ((VC_2 *)(b));
    self->partB = 0;
  }
  if ((deleteA != 0) && (a = self->partA, a != (PartA *)0x0)) {
    delete ((VC_3 *)(a));
    self->partA = 0;
  }
}
