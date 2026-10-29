/* HSTMATCH module=hstp_trans_main.prx start=0x001dfd08 end=0x001dfd84 symbol=FUN_001dfd08 lang=c++ */
/* Clone of src/eboot/FUN_001d1f04.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/pair_items_obj.h"

extern "C" {
extern void FUN_00105470(...);
extern void FUN_00108dac(...);
}
struct VC_0 { virtual void d0(); virtual void m(int); };

/* Reset: clear both items, call the helper's second virtual with 0 and clear the owner's field. */
extern "C" void FUN_001dfd08(PairItemsObj *self)
{
  u32 i;
  char *p;
  
  i = 0;
  p = (char *)self;
  do {
    FUN_00105470(*(u32 *)(p + 0x6c),0);
    i = i + 1;
    p = p + 4;
  } while (i < PAIR_ITEM_COUNT);
  ((VC_0 *)(self->helper))->m((int)(0));
  (*self->owner)->unk60 = 0;
  FUN_00108dac(self);
}
