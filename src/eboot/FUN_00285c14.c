/* HSTMATCH module=EBOOT.BIN start=0x00285c14 end=0x00285c78 symbol=FUN_00285c14 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: inverted if/else branch order; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

enum { UNIT_SIZE = 0x458 };

typedef struct UnitHolder {
  char pad000[0x4e8];
  char unit4e8[UNIT_SIZE];            /* 0x4e8: source unit for the store call */
  char pad940[0x3418 - 0x940];
  char block3418[0x34d0 - 0x3418];    /* 0x3418: unit slot used by both calls */
  int unk34d0;                        /* 0x34d0 */
} UnitHolder;

extern void *DAT_00338ac4;
extern bool FUN_000bae98(void *, void *, int, void *);
extern bool FUN_000bafd0(void *, void *, int, void *);

/* Stores the unit (store != 0) or clears the slot, via the global service object. */
bool FUN_00285c14(UnitHolder *self, int store)
{
  bool ok;
  if (store != 0) {
    ok = FUN_000bae98(DAT_00338ac4, self->block3418, UNIT_SIZE, self->unit4e8);
  }
  else {
    ok = FUN_000bafd0(DAT_00338ac4, self->block3418, 0, 0);
    self->unk34d0 = 0;
  }
  return ok;
}
