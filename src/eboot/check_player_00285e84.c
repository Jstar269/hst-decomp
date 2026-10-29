/* HSTMATCH module=EBOOT.BIN start=0x00285e84 end=0x00285f28 symbol=FUN_00285e84 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: structured loop with early continues and row pointer computed before ret-index test; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

enum { ROSTER_COUNT = 4, UNIT_STRIDE = 0x458 };

typedef struct RosterEntry {    /* size 7 */
  char pad00[6];
  u8 active;                    /* 0x06 */
} RosterEntry;

typedef struct Roster {
  char pad00[0x3e];
  char unk3e[0x58 - 0x3e];      /* 0x3e: key passed to the lookup */
  RosterEntry entries[ROSTER_COUNT]; /* 0x58 */
  char pad74[0x178 - 0x74];
  u8 unk178;                    /* 0x178: nonzero makes the check succeed at once */
} Roster;

extern Roster *DAT_00338ac4;
extern int FUN_000bbba4(void *, void *);

int FUN_00285e84(int units)
{
  if (DAT_00338ac4->unk178 != 0) {
    return 1;
  }

  int res = 0;
  int ret = FUN_000bbba4(DAT_00338ac4, DAT_00338ac4->unk3e);
  int i = 0;
  Roster *roster = DAT_00338ac4;

  for (; i < ROSTER_COUNT; i++, units += UNIT_STRIDE) {
    RosterEntry *entry = &roster->entries[i];
    if (i != ret) {
      continue;
    }
    if (entry->active == 0) {
      continue;
    }
    if (*(u8 *)(units + 0xa6d) == 0) {
      continue;
    }
    if (*(u8 *)(units + 0xa70) == 0) {
      continue;
    }
    res = 1;
    break;
  }
  return res;
}
