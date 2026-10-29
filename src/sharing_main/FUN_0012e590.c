/* HSTMATCH module=hstp_trans_main.prx start=0x0012e590 end=0x0012e5b4 symbol=FUN_0012e590 lang=c99 */
/* Clone of src/eboot/FUN_001233bc.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_001303ec();
extern void FUN_00131538();

/* Passes the result of FUN_001303ec on to FUN_00131538. */
void FUN_0012e590(void)
{
  u32 value;
  
  value = FUN_001303ec();
  FUN_00131538(value);
}
