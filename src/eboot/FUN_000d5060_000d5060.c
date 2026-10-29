/* HSTMATCH module=EBOOT.BIN start=0x000d5060 end=0x000d50dc symbol=FUN_000d5060 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v3) corrected by hand: made the early gate explicit; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/player_record.h"

#define ENTRY_COUNT 4 /* same as PLAYER_SLOTS: entry i is paired with player slot i */

/* 0x1b0-byte entry; the object passed to FUN_0005f1e8 starts at 0x50. */
typedef struct SubEntry {
  char pad00[0x50];
  char sub[0x160];  /* 0x50 */
} SubEntry;         /* size 0x1b0 */

typedef struct EntryGroup {
  SubEntry entry[ENTRY_COUNT];  /* 0x000 */
  char pad6c0[0x50];
  u8 unk710;                    /* 0x710 nonzero: skip the update */
} EntryGroup;

extern PlayerList * DAT_003386b0;
extern void FUN_0005f1e8();

/* For each present player slot, calls FUN_0005f1e8 on the matching entry (unless the group is flagged). */
void FUN_000d5060(EntryGroup *self)
{
  int i;
  
  if (self->unk710 != '\0') return;
  for (i = 0; i < ENTRY_COUNT; i++) {
    if (DAT_003386b0->players[i] != 0) {
      FUN_0005f1e8(self->entry[i].sub,0);
    }
  }
}
