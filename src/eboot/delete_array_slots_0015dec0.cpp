/* HSTMATCH module=EBOOT.BIN start=0x0015dec0 end=0x0015df28 symbol=FUN_0015dec0 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: loop index declared before the walking pointer (s-register order); readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

enum { SLOT_COUNT = 3 };

struct VC_0 { virtual ~VC_0(); };

struct SlotOwner {
  char pad00[0x34];
  VC_0 *slot[SLOT_COUNT];  /* 0x34 */
};

extern "C" {
extern SlotOwner *DAT_003403f8;
}

/* Deletes the three slot objects of the global owner. */
extern "C" void FUN_0015dec0(void)
{
  int i;
  SlotOwner *owner; /* steps one slot per pass, slot[0] is its current slot */
  VC_0 *obj;
  
  i = 0;
  owner = DAT_003403f8;
  do {
    obj = owner->slot[0];
    if (obj != 0) {
      delete obj;
      owner->slot[0] = 0;
    }
    i = i + 1;
    owner = (SlotOwner *)((char *)owner + 4);
  } while (i < SLOT_COUNT);
}
