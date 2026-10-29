/* HSTMATCH module=EBOOT.BIN start=0x001b498c end=0x001b4a70 symbol=FUN_001b498c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/slot_table.h"

#define SHARE_LIMIT 2 /* the slot is freed only when fewer than this many entries share it */

extern void FUN_00062418(int, int);

/* Drop entry `index` of the first four-entry table (unk768); delete the slot it refers to when no other entry of that table shares it, then clear the entry and its flag byte. */
void FUN_001b498c(SlotTable **ctx, int index)
{
  SlotTable *p = *ctx;
  int off = index * 4;
  int *entry = (int *)(off + (int)p + 0x768);
  int *q;
  int *qe;
  int n;
  int i;

  if (p->unk768[index] == 0) return;
  n = 0;
  q = p->unk768;
  qe = p->unk778;
  if (q != qe) {
    do {
      if (*q == *entry) n++;
      q++;
    } while (q != qe);
  }
  if (n < SHARE_LIMIT) {
    for (i = 0; i < SLOT_COUNT; i++) {
      int c = (int)p->slot[i];
      if (c == *entry) {
        int v = (int)p->slot[i];
        if (v != 0) { FUN_00062418(v, 1); p->slot[i] = 0; }
        break;
      }
    }
  }
  *entry = 0;
  p->unk798[index] = 0;
}
