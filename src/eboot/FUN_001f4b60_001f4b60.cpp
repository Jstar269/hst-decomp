/* HSTMATCH module=EBOOT.BIN start=0x001f4b60 end=0x001f4bbc symbol=FUN_001f4b60 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: typed the walking object cursor and the integer argument to its virtual method; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_group.h"

extern "C" {
extern u32 DAT_00338714;
}
struct SlotObj { virtual void d0(); virtual void d1(); virtual void m(int); };
struct Group {
  char pad[0x3a0];
  SlotObj *slot[SLOT_GROUP_COUNT];
};

/* Call every present slot object's method with the global value. */
extern "C" void FUN_001f4b60(Group *group)
{
  SlotObj *slot;
  int i;
  Group *cursor; /* walks the group base 4 bytes per slot */

  i = 0;
  cursor = group;
  do {
    slot = cursor->slot[0];
    if (slot != 0) {
      slot->m(DAT_00338714);
    }
    i = i + 1;
    cursor = (Group *)((char *)cursor + 4);
  } while (i < SLOT_GROUP_COUNT);
}
