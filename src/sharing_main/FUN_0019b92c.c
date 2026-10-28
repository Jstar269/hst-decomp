/* HSTMATCH module=hstp_trans_main.prx start=0x0019b92c end=0x0019b98c symbol=FUN_0019b92c lang=c99 */
/* Clone of src/eboot/FUN_0018f14c.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00000a00();
extern int FUN_00004138();
extern u32 * FUN_000463a0();

int FUN_0019b92c(int param_1,short param_2)
{
  if (param_1 != 0) {
    FUN_000463a0(param_1 + 0xc,0xffffffff);
    FUN_00004138(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
