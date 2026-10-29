/* HSTMATCH module=hstp_trans_main.prx start=0x0023ba20 end=0x0023ba3c symbol=FUN_0023ba20 lang=c99 */
/* Clone of src/eboot/FUN_0022bfb0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern char *DAT_003ea8e8;
extern void FUN_001cdd24();

/* Forward the two arguments to the helper on the sub-object at +0x80 of the global, with mode 2. */
void FUN_0023ba20(u32 a,u32 b)
{
  FUN_001cdd24(DAT_003ea8e8 + 0x80,a,b,2);
}
