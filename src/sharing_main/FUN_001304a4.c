/* HSTMATCH module=hstp_trans_main.prx start=0x001304a4 end=0x001304d0 symbol=FUN_001304a4 lang=c99 */
/* Clone of src/eboot/FUN_001252d0.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003e95c4;
extern int FUN_0013d030();

float FUN_001304a4(void)
{
  int iVar1;
  
  iVar1 = FUN_0013d030(DAT_003e95c4,6);
  return (float)iVar1;
}
