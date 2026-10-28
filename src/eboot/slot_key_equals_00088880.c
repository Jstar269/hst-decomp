/* HSTMATCH module=EBOOT.BIN start=0x00088880 end=0x000888dc symbol=FUN_00088880 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: DAT_003386b8 is unsigned char, slots addressed through a typed struct, else branch re-reads slot 0; readability pass; exact match verified; names and types await human review. */
#include "hst/net_slots.h"

extern unsigned char DAT_003386b8;
extern SlotSelector *DAT_00338ac4;

/* Returns whether `key` equals the key of the current slot (slot 0 when no slot is selected). */
int FUN_00088880(SlotOwner *owner, int key)
{
  SlotEnt *e;
  
  e = 0;
  if ((DAT_003386b8 != 0) &&
     (*((unsigned char *)DAT_00338ac4 + DAT_00338ac4->cur * 7 + 0x5e) != 0) /* flags[cur].on */) {
    e = owner->slots[DAT_00338ac4->cur];
  }
  if (e == 0) {
    e = owner->slots[0];
  }
  return key == e->key;
}
