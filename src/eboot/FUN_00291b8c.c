/* HSTMATCH module=EBOOT.BIN start=0x00291b8c end=0x00291c00 symbol=FUN_00291b8c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: express mode dispatch as a four-case switch with empty cases; readability pass; exact match verified; names and types await human review. */
#include "hst/material_set.h"

extern void FUN_00291c00(MaterialSet *, int);

/* Creates the slots a given mode needs. */
void FUN_00291b8c(MaterialSet *set, int mode)
{
  switch (mode) {
    case 0:
      FUN_00291c00(set, 1);
      FUN_00291c00(set, 3);
      break;
    case 1:
      break;
    case 2:
      FUN_00291c00(set, 4);
      break;
    case 3:
      break;
  }
}
