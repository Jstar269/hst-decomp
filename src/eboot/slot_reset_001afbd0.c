/* HSTMATCH module=EBOOT.BIN start=0x001afbd0 end=0x001afcd4 symbol=FUN_001afbd0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: while (iVar3 >= 0) loop test, declaration order (pointer after the index), the two small clear loops written with block-scoped counter and pointer, with opt_unroll_loops and opt_strength_reduction off (rolled loops); readability pass; exact match verified; names and types await human review. */
#pragma opt_unroll_loops off
#pragma opt_strength_reduction off
#include "hst/types.h"
#include "hst/slot_table.h"

extern int FUN_00062418();

/* Delete every owned slot object (except SLOT_KEEP) and put the counters back to their idle values. */
void FUN_001afbd0(SlotTable *self)
{
  u32 k;
  int index;
  void **slotp;
  int *w;
  
  index = SLOT_COUNT - 1;
  slotp = &self->slot[SLOT_COUNT - 1];
  do {
    if ((index != SLOT_KEEP) && (*slotp != 0)) {
      FUN_00062418(*slotp,1);
      *slotp = 0;
    }
    index = index + -1;
    slotp = slotp + -1;
  } while (index >= 0);
  self->court_sound = -1;
  self->unk7a0 = -1;
  self->unk7a4 = -1;
  self->unk7a8 = -1;
  self->unk7ac = -1;
  self->unk7b0 = SLOT_COUNT;
  self->unk7b4 = -1;
  self->unk7b8 = SLOT_COUNT;
  self->unk7bc = -1;
  self->unk7c0 = SLOT_COUNT;
  self->unk7c4 = -1;
  self->unk7c8 = SLOT_COUNT;
  k = 0;
  w = (int *)self;
  do {
    w[0x768 / 4] = 0; /* unk768[k] */
    self->unk798[k] = 0;
    k = k + 1;
    w = w + 1;
  } while (k < 4);
  {
    u32 j = 0;
    int *q = (int *)self;
    do {
      j = j + 1;
      q[0x778 / 4] = 0; /* unk778[j] */
      q = q + 1;
    } while (j < 4);
  }
  self->unk788 = 0;
  {
    u32 j = 0;
    int *q = (int *)self;
    do {
      j = j + 1;
      q[0x78c / 4] = 0; /* unk78c[j] */
      q = q + 1;
    } while (j < 2);
  }
  self->unk794 = 0;
}
