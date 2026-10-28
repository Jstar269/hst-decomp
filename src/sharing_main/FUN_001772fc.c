/* HSTMATCH module=hstp_trans_main.prx start=0x001772fc end=0x0017731c symbol=FUN_001772fc lang=c99 */
/* Clone of src/eboot/FUN_0016b138.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_00177d4c();

u16 FUN_001772fc(void)
{
  int iVar1;
  
  iVar1 = FUN_00177d4c();
  return *(u16 *)(iVar1 + 0x1036);
}
