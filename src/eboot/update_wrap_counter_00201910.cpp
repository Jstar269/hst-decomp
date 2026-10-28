/* HSTMATCH module=EBOOT.BIN start=0x00201910 end=0x002019cc symbol=FUN_00201910 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: C++ virtual call on slot 2 (VC with three virtuals), typed object view with nine 0x8c-byte records, and the nine FUN_00217940 calls written out (a for loop stays rolled); readability pass; exact match verified; names and types await human review. */
#include "hst/menu_obj.h"

extern "C" void FUN_00201604(MenuObj *);
extern "C" void FUN_00217940(Rec8c *);

/* Per-frame update: bumps the wrapping counter, mirrors it into the cell, steps the state machine, updates all records. */
extern "C" void FUN_00201910(MenuObj *self)
{
  if (self->w04 != 0) {
    self->w04->v2();
    int next = self->counter + 1;
    self->counter = next;
    if (next >= MENU_COUNTER_WRAP) {
      self->counter = 0;
    }
    Cell *cell = self->cell56c;
    cell->unk24 = cell->unk28 + self->counter;
    FUN_00201604(self);
    FUN_00217940(&self->recs[0]);
    FUN_00217940(&self->recs[1]);
    FUN_00217940(&self->recs[2]);
    FUN_00217940(&self->recs[3]);
    FUN_00217940(&self->recs[4]);
    FUN_00217940(&self->recs[5]);
    FUN_00217940(&self->recs[6]);
    FUN_00217940(&self->recs[7]);
    FUN_00217940(&self->recs[8]);
  }
}
