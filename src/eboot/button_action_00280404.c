/* HSTMATCH module=EBOOT.BIN start=0x00280404 end=0x002805fc symbol=FUN_00280404 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode corrected by hand: the nested if/else chain is a switch (its labels are exactly the groups the chain
   tests), the two flag expressions are a local computed with a conditional operator, and the case labels are written in
   reverse of the natural order because MWCC emits switch compares in reverse label order (matching idiom: case order).
   Exact match verified; names and types await human review. */
#include "hst/slot_owner.h"

typedef struct Slot {
  unsigned char active; /* 0x00 */
  char pad01[0x11f];
} Slot;                 /* 0x120 bytes per slot */

extern unsigned char DAT_003386b8;
extern ActiveOwner *DAT_00338ac4;
extern Slot DAT_003418bc[];
extern int DAT_0034a678; /* current state id, changed through FUN_00234158 */

extern void FUN_00234158(int *, int);

void FUN_00280404(void)
{
  unsigned char ownerFlag;
  unsigned char handled;
  int idx;

  idx = (DAT_003386b8 != 0 && DAT_00338ac4 != 0) ? DAT_00338ac4->slotIndex : 0;

  ownerFlag = 0;
  if (DAT_00338ac4 != 0 && DAT_00338ac4->flag != 0)
    ownerFlag = 1;

  handled = 0;
  switch (DAT_0034a678) {
  case 0x2a:
    if (DAT_003418bc[idx].active == 0) {
      FUN_00234158(&DAT_0034a678, 0x20);
      handled = 1;
    }
    break;
  case 0x26:
  case 0x27:
  case 0x28:
    FUN_00234158(&DAT_0034a678, 0x20);
    handled = 1;
    break;
  case 0x37:
    break;
  case 0x29:
    if (ownerFlag) {
      FUN_00234158(&DAT_0034a678, 0x20);
      handled = 1;
    }
    break;
  case 0x31:
    if (DAT_003418bc[idx].active == 0) {
      FUN_00234158(&DAT_0034a678, 0x2b);
      handled = 1;
    }
    break;
  case 0x2d:
  case 0x2e:
  case 0x2f:
    FUN_00234158(&DAT_0034a678, 0x2b);
    handled = 1;
    break;
  case 0x39:
  case 0x3a:
    break;
  case 0x30:
    if (ownerFlag) {
      FUN_00234158(&DAT_0034a678, 0x2b);
      handled = 1;
    }
    break;
  }
  if (!handled)
    FUN_00234158(&DAT_0034a678, 0x1e);
}
