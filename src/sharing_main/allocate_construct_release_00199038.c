/* HSTMATCH module=hstp_trans_main.prx start=0x00199038 end=0x00199098 symbol=FUN_00199038 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: reused the allocation result through construction, copy, and release; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003ea8e8;
extern void FUN_00000a00();
extern int FUN_00000bcc();
extern u32 * FUN_00011090();
extern int FUN_00198ee4();

void FUN_00199038(void)
{
  int *object = (int *)FUN_00000bcc(0x979c0);
  if (object != (int *)0) {
    object = (int *)FUN_00198ee4((int)object);
  }
  FUN_00011090(DAT_003ea8e8, object, 0x979c0);
  FUN_00000a00(object);
}
