/* HSTMATCH module=EBOOT.BIN start=0x0017fe4c end=0x0017fff4 symbol=FUN_0017fe4c lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: delete[] call takes the tested global as its argument (Ghidra dropped it), loop index declared before the walking pointer; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/chrsel_screen.h"

extern "C" {
extern u8 DAT_00309130;
extern int DAT_0034151c;
extern void FUN_00000788(...);
extern void FUN_000009e4(int);
extern void FUN_00000a00(...);
extern void FUN_0018059c(...);
extern int FUN_002175d4(...);
extern void FUN_000ff760(...);
}
#define SLOTS_WORD 0x48a /* word index of the slot array in the screen object */

struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };

/* Deleting destructor of the character-select screen: releases the shared global, the layout and the
   owned slot objects, tears down the bound sub-objects and arrays, frees the object when delete_flag > 0. */
extern "C" ChrSelScreen * FUN_0017fe4c(ChrSelScreen *self,short delete_flag)
{
  int i;
  void **walker;

  if (self != (ChrSelScreen *)0x0) {
    self->vtable = &DAT_00309130;
    if (DAT_0034151c != 0) {
      FUN_000009e4(DAT_0034151c);
      DAT_0034151c = 0;
    }
    if (self->layout != 0) {
      delete ((VC_0 *)(self->layout));
      self->layout = 0;
    }
    i = 0;
    walker = (void **)self; /* walks from the object start; slots[] begins at a fixed word index */
    do {
      if (walker[SLOTS_WORD] != 0) {
        delete ((VC_1 *)(walker[SLOTS_WORD]));
        walker[SLOTS_WORD] = 0;
      }
      i = i + 1;
      walker = walker + 1;
    } while (i < CHRSEL_SLOT_COUNT);
    FUN_0018059c(self);
    FUN_00000788(self->arrC,FUN_000ff760,CHRSEL_ELEM_SIZE,CHRSEL_ELEM_COUNT);
    FUN_00000788(self->arrB,FUN_000ff760,CHRSEL_ELEM_SIZE,CHRSEL_ELEM_COUNT);
    FUN_00000788(self->arrA,FUN_000ff760,CHRSEL_ELEM_SIZE,CHRSEL_ELEM_COUNT);
    FUN_002175d4(self->s16b4,-1);
    FUN_002175d4(self->s1628,-1);
    FUN_002175d4(self->s159c,-1);
    FUN_002175d4(self->s1510,-1);
    FUN_002175d4(self->s1484,-1);
    FUN_002175d4(self->s13f8,-1);
    FUN_002175d4(self->s136c,-1);
    FUN_002175d4(self->s12e0,-1);
    FUN_002175d4(self->s1254,-1);
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
