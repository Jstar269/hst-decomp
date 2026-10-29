/* HSTMATCH module=EBOOT.BIN start=0x00254b58 end=0x00254bd0 symbol=FUN_00254b58 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: replaced numeric address 0x34179c with &DAT_0034179c; readability pass; exact match verified; names and types await human review. */

#include "hst/slot_queue.h"

extern char DAT_0034179c;
extern void *DAT_0034b340[SLOT_QUEUE_COUNT];
extern void FUN_00194e3c();
extern unsigned int FUN_001b1c44();
extern void FUN_00253f38();

/* Starts the entry of a slot (if it has one) and marks the slot ready. */
void FUN_00254b58(SlotQueueObj *self,int index)
{
  if (DAT_0034b340[index] != 0) {
    FUN_00194e3c(DAT_0034b340[index],index,0,1);
    FUN_00253f38(index);
    self->ready[index] = 1;
    FUN_001b1c44(&DAT_0034179c,0x16);
  }
}
