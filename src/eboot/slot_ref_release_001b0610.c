/* HSTMATCH module=EBOOT.BIN start=0x001b0610 end=0x001b06d4 symbol=FUN_001b0610 lang=c99 */
/* Hand-written reconstruction from the disassembly; readability pass; exact match verified; names and types await human review. */
#include "hst/slot_table.h"

extern void FUN_00062418(void *, int);

/* Release reference `index` of the second 4-entry table: when no other entry refers to the same slot, delete that slot's object; then clear the entry. */
void FUN_001b0610(SlotTable *table, int index)
{
  SlotTable *p = table;
  int off = index * 4;
  int *entry = (int *)(off + (int)p + 0x778);   /* unk778[index] */
  int *cur;
  int *end;
  int matches;
  int i;

  if (p->unk778[index] == 0) return;
  matches = 0;
  cur = p->unk778;
  end = &p->unk788;
  if (cur != end) {
    do {
      if (*cur == *entry) matches++;
      cur++;
    } while (cur != end);
  }
  if (matches < 2) {
    for (i = 0; i < SLOT_COUNT; i++) {
      void *candidate = p->slot[i];
      if ((int)candidate == *entry) {
        void *object = p->slot[i];
        if (object != 0) { FUN_00062418(object, 1); p->slot[i] = 0; }
        break;
      }
    }
  }
  *entry = 0;
}
