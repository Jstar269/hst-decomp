/* HSTMATCH module=EBOOT.BIN start=0x00285c78 end=0x00285d04 symbol=FUN_00285c78 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: used the explicit zero-count branch and a shared result updated by the loop break; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

enum { UNIT_STRIDE = 0x458, UNIT_COUNT_SHORT = 2, UNIT_COUNT_FULL = 4 };

typedef struct UnitList {
  char pad00[0x5c];
  int full;             /* 0x5c: nonzero when all four units are in use */
} UnitList;

extern u32 *DAT_00338ac4;
extern int FUN_000bbba4(void *a, void *b);

/* Returns the index of the first unit that matches the lookup result, or 0. */
int FUN_00285c78(char *units)
{
  int count;
  int match;
  int result;
  int i;

  if (DAT_00338ac4 == 0) return 0;
  else {
    if (((UnitList *)units)->full == 0) count = UNIT_COUNT_SHORT;
    else count = UNIT_COUNT_FULL;
    match = FUN_000bbba4(DAT_00338ac4, (char *)DAT_00338ac4 + 0x3e);
    result = 0;
    i = 0;
    if (count > 0) {
      do {
        if (*(int *)(units + 0x1bd8) == match) {
          result = i;
          break;
        }
        ++i;
        units += UNIT_STRIDE;
      } while (i < count);
    }
    return result;
  }
}
