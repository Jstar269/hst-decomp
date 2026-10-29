/* HSTMATCH module=EBOOT.BIN start=0x001178f0 end=0x00117a54 symbol=FUN_001178f0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review.
   Ninth-slot ring buffer (entry 0x70 bytes at +0x80): the reset branch must be `if (reset != 0) {init}
   else {store}` so that the likely branch jumps to the shared store, and the unk60 test is inverted the
   same way (`if (unk60 != idx2) unk60 = 0; else unk60 = (idx2+1)%9;`). */

#include "hst/wheel_state.h"

extern unsigned char *DAT_003386b0;

/* Pushes src as the next entry of the nine-slot ring (optionally resetting the state first) and updates the ring indices. */
void FUN_001178f0(WheelState *self, const WheelEntry *src, int value, int reset)
{
  WheelEntry *entry;
  int next;
  int idx;
  int idx2;

  if (*(int *)(DAT_003386b0 + 0x3c) == 7) {
    return;
  }
  if (reset != 0) {
    self->unk4c = 0;
    self->unk50 = 0;
    self->unk54 = 0;
    self->unk58 = 0;
    self->unk5c = -1;
    self->unk60 = -1;
    self->unk64 = -1;
    self->unk6c = -1;
    self->unk40 = 0;
    self->unk54 = value;
  }
  else {
    self->unk54 = value;
  }
  next = self->unk5c + 1;
  idx = next % WHEEL_SLOTS;
  self->unk5c = next;
  self->unk5c = idx;
  entry = &self->ring[idx];
  entry->unk60 = value;
  entry->unk61 = reset;
  entry->unk00 = src->unk00;
  entry->unk10 = src->unk10;
  entry->unk20 = src->unk20;
  entry->unk24 = src->unk24;
  entry->unk28 = src->unk28;
  entry->unk2c = src->unk2c;
  entry->unk30 = src->unk30;
  entry->unk34 = src->unk34;
  entry->unk36 = src->unk36;
  entry->unk37 = src->unk37;
  entry->unk38 = src->unk38;
  entry->unk38 = self->unk58;
  entry->unk40 = 0;
  entry->unk50 = 0;
  entry->unk54 = 0;
  entry->unk58 = 0;
  entry->unk5c = 0;
  idx2 = (self->unk5c + 1) % WHEEL_SLOTS;
  self->unk64 = idx2;
  if (self->unk60 != idx2) {
    self->unk60 = 0;
  }
  else {
    self->unk60 = (idx2 + 1) % WHEEL_SLOTS;
  }
  self->unk6c = 0;
}
