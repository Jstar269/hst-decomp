/* HSTMATCH module=EBOOT.BIN start=0x0015d0f0 end=0x0015d16c symbol=FUN_0015d0f0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: indexed the global destination array instead of walking a local output pointer; readability pass; exact match verified; names and types await human review. */
#include "hst/profile_data.h"

#define TABLE_SIZE 256 /* entries in the flag table */

typedef struct Entry {
  char pad00[0x20];
  int first;  /* 0x20 first profile counter of the entry */
} Entry;

extern unsigned char DAT_0034100c[];
extern ProfileData *DAT_00340400;
extern Entry *FUN_0015cce8(unsigned int, int);

/* Refills the flag table from the profile counters of the entry (0 where an index has no entry). */
void FUN_0015d0f0(unsigned int owner) {
  int i = 0;
  do {
    Entry *entry = FUN_0015cce8(owner, i);
    if (entry != 0) {
      DAT_0034100c[i] = DAT_00340400->counts[i + entry->first];
    } else {
      DAT_0034100c[i] = 0;
    }
    ++i;
  } while (i < TABLE_SIZE);
}
