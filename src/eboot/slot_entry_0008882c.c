/* HSTMATCH module=EBOOT.BIN start=0x0008882c end=0x00088880 symbol=FUN_0008882c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v3) corrected by hand: modelled on src/eboot/slot_key_equals_00088880.c (typed slot array, else branch re-reads slot 0), the 7-byte flag records as a typed array reached through a local record pointer; readability pass; exact match verified; names and types await human review. */
#include "hst/net_slots.h"

extern unsigned char DAT_003386b8;
extern SlotSelector *DAT_00338ac4;

/* Returns the current slot's object (slot 0 when no slot is selected or enabled). */
SlotEnt *FUN_0008882c(SlotOwner *owner)
{
  SlotEnt *e = 0;
  if (DAT_003386b8 != 0) {
    SlotFlag *flag = &DAT_00338ac4->flags[DAT_00338ac4->cur];
    if (flag->on != 0) {
      e = owner->slots[DAT_00338ac4->cur];
    }
  }
  if (e == 0) {
    e = owner->slots[0];
  }
  return e;
}
