/* HSTMATCH module=EBOOT.BIN start=0x001277e8 end=0x00127870 symbol=FUN_001277e8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p1), refined by hstperm.py random mutation (perm-p1/r00/f0385_001277e8_m14.c), corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/motion_obj.h"

extern u32 DAT_0033b4a8;  /* entry table, MOTION_TABLE_COUNT entries */
extern void FUN_0005743c();
extern void FUN_00093024();

/* Hand every non-empty table entry to the helper together with the item link at +0x58. */
void FUN_001277e8(int self)
{
  MotionEntry *entry;
  int link;
  int i;
  int offset;

  FUN_00093024();
  link = *(int *)(self + 0x58);
  if (link != 0) {
    i = 0;
    offset = 0;
    do {
      entry = (MotionEntry *)(DAT_0033b4a8 + offset);
      if ((entry != (MotionEntry *)0x0) && (entry->unk00 != 0)) {
        FUN_0005743c(link,i,entry,0);
      }
      i = i + 1;
      offset = offset + sizeof(MotionEntry);
    } while (i < MOTION_TABLE_COUNT);
  }
}
