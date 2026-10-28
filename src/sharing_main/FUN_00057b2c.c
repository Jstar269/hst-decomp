/* HSTMATCH module=hstp_trans_main.prx start=0x00057b2c end=0x00057b58 symbol=FUN_00057b2c lang=c99 */
/* Clone of src/eboot/FUN_00092ff8.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00057bdc();
extern void FUN_00055d24();

void FUN_00057b2c(u32 param_1)
{
  FUN_00057bdc();
  FUN_00055d24(param_1);
}
