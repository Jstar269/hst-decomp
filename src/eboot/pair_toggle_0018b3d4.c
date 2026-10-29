/* HSTMATCH module=EBOOT.BIN start=0x0018b3d4 end=0x0018b490 symbol=FUN_0018b3d4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: flag byte at +0x6f of the input state is unsigned char (lbu), loop index split from the call-result temporary and declared before the pointer (saved-register assignment); the screen stays an int base because a PhaseScreen pointer hoists the flag address out of the loop; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

#define PHASE_IDLE 4 /* value of the phase counter (at +0x54) in which nothing is updated */

extern char DAT_002e0b44[];
extern char DAT_002e0b5c[];
extern char DAT_002e0bb7[];
extern void FUN_000ffb3c();
extern int FUN_001026b8();
extern void FUN_001031e8();
extern int FUN_001039d8();

/* Looks up two named items below the screen's node and shows or hides both from one flag byte of the input state. */
void FUN_0018b3d4(int screen)
{
  int node;
  int j;
  int *item_ptr;
  int items [2];
  
  if (*(int *)(screen + 0x54) != PHASE_IDLE) {
    node = FUN_001039d8(screen,(u8 *)DAT_002e0b44,0);
    items[0] = FUN_001026b8(node,(u8 *)DAT_002e0b5c);
    node = FUN_001039d8(screen,(u8 *)DAT_002e0b44,0);
    items[1] = FUN_001026b8(node,(u8 *)(DAT_002e0bb7 + 1));
    j = 0;
    item_ptr = items;
    do {
      FUN_000ffb3c(*item_ptr,*(unsigned char *)(screen + 0x6f) != 0 ^ 1);
      j = j + 1;
      item_ptr = item_ptr + 1;
    } while (j < 2);
    FUN_001031e8(screen);
  }
}
