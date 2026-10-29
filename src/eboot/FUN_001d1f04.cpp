/* HSTMATCH module=EBOOT.BIN start=0x001d1f04 end=0x001d1f80 symbol=FUN_001d1f04 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5), refined by hstperm.py tag p4 random mutation from try/gen-a5/v17/FUN_001d1f04.cpp; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/pair_items_obj.h"

extern "C" {
extern void FUN_000ffb3c(...);
extern void FUN_00103480(...);
}
struct VC_0 { virtual void d0(); virtual void m(int); };

/* Reset: clear both items, call the helper's second virtual with 0 and clear the owner's field. */
extern "C" void FUN_001d1f04(PairItemsObj *self)
{
  u32 i;
  char *p;
  
  i = 0;
  p = (char *)self;
  do {
    FUN_000ffb3c(*(u32 *)(p + 0x6c),0);
    i = i + 1;
    p = p + 4;
  } while (i < PAIR_ITEM_COUNT);
  ((VC_0 *)(self->helper))->m((int)(0));
  (*self->owner)->unk60 = 0;
  FUN_00103480(self);
}
