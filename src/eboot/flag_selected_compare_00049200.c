/* HSTMATCH module=EBOOT.BIN start=0x00049200 end=0x00049244 symbol=FUN_00049200 lang=c99 */
/* Clone of src/sharing_main/flag_selected_compare_00049084.c (hstclone.py tag u6cr5e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: expressed the byte selector as a switch and materialized the helper result before comparison; exact match verified; names and types await human review. */
#include "hst/types.h"
extern int DAT_002d0738;
extern u8 DAT_00311140;
extern int FUN_002b77e0();
bool FUN_00049200(void)
{
  int expected;
  int result;
  switch (DAT_00311140) {
    case 0: expected = -1; break;
    default: expected = DAT_002d0738; break;
  }
  result = FUN_002b77e0();
  return result == expected;
}
