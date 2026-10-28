/* HSTMATCH module=hstp_trans_main.prx start=0x0019caa0 end=0x0019cae0 symbol=FUN_0019caa0 lang=c99 */
/* Clone of src/eboot/FUN_00190290.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_00003e04();
extern u32 * FUN_0019d090();

int FUN_0019caa0(int param_1,int param_2)
{
  FUN_00003e04();
  FUN_0019d090(param_1 + 0xc,param_2 + 0xc);
  return param_1;
}
