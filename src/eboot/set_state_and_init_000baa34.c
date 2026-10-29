/* HSTMATCH module=EBOOT.BIN start=0x000baa34 end=0x000baaa4 symbol=FUN_000baa34 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (inputs/pseudocode/ram-0x000baa34.c, no hstgen tag) corrected by hand: the if-chain rewritten as a switch (cases 4/8 share the call, case 10 empty); exact match verified; names and types await human review. */
#include "hst/adhoc_net.h"
extern AdhocNet *DAT_00338ac4;
extern int FUN_000bda40(AdhocNet *, void *, unsigned short, int, int);

/* Stores the service state; the two matching states start the matching session. */
void FUN_000baa34(AdhocNet *self, int state)
{
  self->state = state;
  switch (state) {
  case 4:
  case 8:
    self->unk17c =
      FUN_000bda40(DAT_00338ac4, DAT_00338ac4->unk38,
                   self->config.unk0c, ADHOC_MAX_PAYLOAD, 0) & 0xff;
    break;
  case 10:
    break;
  }
}
