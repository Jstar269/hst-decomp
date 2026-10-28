/* HSTMATCH module=EBOOT.BIN start=0x00285c14 end=0x00285c78 symbol=FUN_00285c14 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: inverted if/else branch order; exact match verified; names and types await human review. */

#include "hst/types.h"
extern void *DAT_00338ac4;
extern bool FUN_000bae98(void *, void *, int, void *);
extern bool FUN_000bafd0(void *, void *, int, void *);

bool FUN_00285c14(char *param_1, int param_2)
{
  bool r;
  if (param_2 != 0) {
    r = FUN_000bae98(DAT_00338ac4, param_1 + 0x3418, 0x458, param_1 + 0x4e8);
  }
  else {
    r = FUN_000bafd0(DAT_00338ac4, param_1 + 0x3418, 0, 0);
    *(int *)(param_1 + 0x34d0) = 0;
  }
  return r;
}
