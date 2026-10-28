/* HSTMATCH module=hstp_trans_main.prx start=0x0017d188 end=0x0017d1d4 symbol=FUN_0017d188 lang=c99 */
/* Clone of src/eboot/FUN_00170ebc.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int DAT_003ea8ec;

void FUN_0017d188(void)
{
  int iVar1;
  
  iVar1 = DAT_003ea8ec;
  if (DAT_003ea8ec != 0) {
    *(u32 *)(DAT_003ea8ec + 0x74) = 0x3f800000;
    *(u32 *)(iVar1 + 0x78) = 0x3f800000;
    iVar1 = DAT_003ea8ec;
    *(u32 *)(**(int **)(DAT_003ea8ec + 4) + 0x60) = 0x43700000;
    *(u32 *)(**(int **)(iVar1 + 4) + 100) = 0x43080000;
  }
}
