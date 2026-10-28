/* HSTMATCH module=hstp_trans_main.prx start=0x00297288 end=0x00297314 symbol=FUN_00297288 lang=c99 */
/* Clone of src/eboot/FUN_00285c78.c (hstclone.py tag u6cr4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: used the explicit zero-count branch and a shared result updated by the loop break; exact match verified; names and types await human review. */
#include "hst/types.h"
extern u32 *DAT_003e1e04;
extern int FUN_000bf018(void *param_1, void *param_2);

int FUN_00297288(char *param_1)
{
  int count;
  int match;
  int result;
  int i;

  if (DAT_003e1e04 == 0) return 0;
  else {
    if (*(int *)(param_1 + 0x5c) == 0) count = 2;
    else count = 4;
    match = FUN_000bf018(DAT_003e1e04, (char *)DAT_003e1e04 + 0x3e);
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
