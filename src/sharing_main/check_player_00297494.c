/* HSTMATCH module=hstp_trans_main.prx start=0x00297494 end=0x00297538 symbol=FUN_00297494 lang=c99 */
/* Clone of src/eboot/check_player_00285e84.c (hstclone.py tag s10170049g1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: structured loop with early continues and row pointer computed before ret-index test; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int DAT_003e1e04;
extern int FUN_000bf018(int, int);

int FUN_00297494(int param_1)
{
  if (*(u8 *)(DAT_003e1e04 + 0x178) != 0) {
    return 1;
  }

  int res = 0;
  int ret = FUN_000bf018(DAT_003e1e04, DAT_003e1e04 + 0x3e);
  int i = 0;
  int p = DAT_003e1e04;

  for (; i < 4; i++, p += 7, param_1 += 0x458) {
    u8 *row = (u8 *)p + 88;
    if (i != ret) {
      continue;
    }
    if (row[6] == 0) {
      continue;
    }
    if (*(u8 *)(param_1 + 0xa6d) == 0) {
      continue;
    }
    if (*(u8 *)(param_1 + 0xa70) == 0) {
      continue;
    }
    res = 1;
    break;
  }
  return res;
}
