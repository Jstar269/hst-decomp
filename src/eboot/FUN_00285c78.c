/* HSTMATCH module=EBOOT.BIN start=0x00285c78 end=0x00285d04 symbol=FUN_00285c78 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: used the explicit zero-count branch and a shared result updated by the loop break; exact match verified; names and types await human review. */
#include "hst/types.h"
extern u32 *DAT_00338ac4;
extern int FUN_000bbba4(void *param_1, void *param_2);

int FUN_00285c78(char *param_1)
{
  int count;
  int match;
  int result;
  int i;

  if (DAT_00338ac4 == 0) return 0;
  else {
    if (*(int *)(param_1 + 0x5c) == 0) count = 2;
    else count = 4;
    match = FUN_000bbba4(DAT_00338ac4, (char *)DAT_00338ac4 + 0x3e);
    result = 0;
    i = 0;
    if (count > 0) {
      do {
        if (*(int *)(param_1 + 0x1bd8) == match) {
          result = i;
          break;
        }
        ++i;
        param_1 += 0x458;
      } while (i < count);
    }
    return result;
  }
}
