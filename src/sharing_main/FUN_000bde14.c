/* HSTMATCH module=hstp_trans_main.prx start=0x000bde14 end=0x000bde38 symbol=FUN_000bde14 lang=c99 */
/* Clone of src/eboot/FUN_000baaa4.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_002c7c78();

bool FUN_000bde14(void)
{
  int iVar1;
  
  iVar1 = FUN_002c7c78();
  return iVar1 == 1;
}
