/* HSTMATCH module=EBOOT.BIN start=0x0008ad40 end=0x0008add8 symbol=FUN_0008ad40 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a3/v10) corrected by hand: the byte flag at +0x4c is unsigned char (lbu) and the loop counter is unsigned and indexes the slot table; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/play_flow.h"

extern u8 DAT_003386b8;
extern u32 DAT_00338af0;
extern void FUN_0009619c();

enum { COUNTDOWN_START = 0x708 }; /* initial value of the countdown when first armed */

/* Pass every non-empty slot on to the helper; the first time through, arm the object and start its countdown. */
void FUN_0008ad40(PlayFlowObj *self)
{
  u32 i;

  if ((DAT_003386b8 != 0) && (DAT_00338af0 != 0)) {
    i = 0;
    do {
      if (self->slots[i] != 0) {
        FUN_0009619c(self->slots[i],self->unk5c,self->unk64);
      }
      i = i + 1;
    } while (i < PLAY_FLOW_SLOTS);
    if (self->armed == 0) {
      self->armed = 1;
      self->countdown = COUNTDOWN_START;
    }
  }
}
