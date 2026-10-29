/* HSTMATCH module=EBOOT.BIN start=0x000bb06c end=0x000bb0f4 symbol=FUN_000bb06c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: 7-byte entries as a typed struct array with an unsigned char flag (lbu), for-loop index declared first (s1/s0 order), typed pointer arguments; exact match verified; readability pass; names and types await human review. */
#include "hst/peer_slots.h"

extern char DAT_002d5258[];
extern void FUN_000ba3ac(char *, int);
extern int FUN_002b7df0(int, char *);

/* Calls the matching service for every in-use peer slot except the local one; logs failures; always returns 1. */
int FUN_000bb06c(PeerTable *table)
{
  int i;
  for (i = 0; i < PEER_SLOT_COUNT; i++) {
    if (table->slots[i].on != 0 && i != table->cur) {
      int result = FUN_002b7df0(table->matching_id, table->slots[i].mac);
      if (result < 0) {
        FUN_000ba3ac(DAT_002d5258, result);
      }
    }
  }
  return 1;
}
