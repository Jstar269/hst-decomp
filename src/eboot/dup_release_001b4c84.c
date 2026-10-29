/* HSTMATCH module=EBOOT.BIN start=0x001b4c84 end=0x001b4d4c symbol=FUN_001b4c84 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/slot_table.h"

#define SHARE_LIMIT 2 /* the slot is freed only when fewer than this many entries share it */

extern void FUN_00062418(int, int);

/* Like FUN_001b498c for the second four-entry table (unk778), without a flag byte: drop entry `index`, deleting its slot when no other entry shares it. */
void FUN_001b4c84(SlotTable **ctx,int index)
{
  SlotTable *p = *ctx;
  int off = index * 4;
  int *entry = (int *)(off + (int)p + 0x778);
  int *q;
  int *qe;
  int n;
  int i;

  if (p->unk778[index] == 0) return;
  n = 0;
  q = p->unk778;
  qe = p->unk778 + 4;
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
}
