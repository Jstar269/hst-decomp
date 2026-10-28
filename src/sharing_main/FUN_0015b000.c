/* HSTMATCH module=hstp_trans_main.prx start=0x0015b000 end=0x0015b014 symbol=FUN_0015b000 lang=c99 */
/* Clone of src/eboot/FUN_0014f000.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

int FUN_0015b000(u32 *param_1)
{
  char cVar1;
  
  cVar1 = *(char *)*param_1;
  *param_1 = (unsigned int)((char *)*param_1 + 1);
  return (int)cVar1;
}
