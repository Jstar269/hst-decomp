/* HSTMATCH module=EBOOT.BIN start=0x0011a078 end=0x0011a16c symbol=FUN_0011a078 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: corrected helper prototypes and argument order, index arithmetic, and switch layout; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/track_slots.h"

extern u32 DAT_00338c20;
extern u8 FUN_00057b58(int *, float, int, int);
extern void FUN_00058ddc(int *, int, int);
extern void FUN_00058ec4(int *, float, int);
extern void FUN_00058f38(int *, float, int);
extern void FUN_00059084(int *, int);
extern void FUN_000fb544();

/* Resets the handle of one slot to its start state and marks the slot active. */
void FUN_0011a078(TrackSlots *self,int index)
{
  int **slot;
  int offset;
  
  offset = index * 4;
  offset += (int)self;
  slot = (int **)(offset + 0x48);
  FUN_00057b58(*slot,0.0f,0,0);
  FUN_00058f38(*slot,0.0f,-1);
  FUN_00058ec4(*slot,1.0f,-1);
  FUN_00058ddc(*slot,0,-1);
  FUN_00059084(*slot,-1);
  self->active[index] = 1;
  switch (index) {
  case 9:
  case 1:
  case 5:
  case 0x11:
  case 0xb:
    self->unk44 = 1;
    FUN_000fb544(DAT_00338c20);
    break;
  default:
    break;
  }
}
