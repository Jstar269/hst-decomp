/* HSTMATCH module=EBOOT.BIN start=0x00254114 end=0x0025418c symbol=FUN_00254114 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: declared the helper integer argument and ordered the counter before the table cursor; readability pass; exact match verified; names and types await human review. */
#include "hst/slot_queue.h"

extern unsigned int DAT_0034a79c;
extern int DAT_0034b340[SLOT_QUEUE_COUNT];
extern void FUN_000006e8();
extern void FUN_00092ff8(int);
extern void FUN_00055e48();

/* Releases the four slot entries and the object held in DAT_0034a79c. */
void FUN_00254114(void)
{
  int i;
  int *entry;
  
  i = 0;
  entry = DAT_0034b340;
  do {
    if (*entry != 0) {
      FUN_00092ff8(*entry);
    }
    i = i + 1;
    entry = entry + 1;
  } while (i < SLOT_QUEUE_COUNT);
  if (DAT_0034a79c != 0) {
    FUN_000006e8(DAT_0034a79c,FUN_00055e48);
    DAT_0034a79c = 0;
  }
}
