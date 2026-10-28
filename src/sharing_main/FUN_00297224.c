/* HSTMATCH module=hstp_trans_main.prx start=0x00297224 end=0x00297288 symbol=FUN_00297224 lang=c99 */
/* Clone of src/eboot/FUN_00285c14.c (hstclone.py tag u5fr3s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: inverted if/else branch order; exact match verified; names and types await human review. */

#include "hst/types.h"
extern void *DAT_003e1e04;
extern bool FUN_000be288(void *, void *, int, void *);
extern bool FUN_000be418(void *, void *, int, void *);

bool FUN_00297224(char *param_1, int param_2)
{
  bool r;
  if (param_2 != 0) {
    r = FUN_000be288(DAT_003e1e04, param_1 + 0x3418, 0x458, param_1 + 0x4e8);
  }
  else {
    r = FUN_000be418(DAT_003e1e04, param_1 + 0x3418, 0, 0);
    *(int *)(param_1 + 0x34d0) = 0;
  }
  return r;
}
