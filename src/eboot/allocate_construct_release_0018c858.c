/* HSTMATCH module=EBOOT.BIN start=0x0018c858 end=0x0018c8b8 symbol=FUN_0018c858 lang=c99 */
/* Clone of src/sharing_main/allocate_construct_release_00199038.c (hstclone.py tag u4r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2) corrected by hand: reused the allocation result through construction, copy, and release; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003415a8;
extern void FUN_00000a00();
extern int FUN_00000bcc();
extern u32 * FUN_00011090();
extern int FUN_0018c704();

void FUN_0018c858(void)
{
  int *object = (int *)FUN_00000bcc(0x979c0);
  if (object != (int *)0) {
    object = (int *)FUN_0018c704((int)object);
  }
  FUN_00011090(DAT_003415a8, object, 0x979c0);
  FUN_00000a00(object);
}
