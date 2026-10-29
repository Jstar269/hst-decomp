/* HSTMATCH module=hstp_trans_main.prx start=0x002bd64c end=0x002bd670 symbol=FUN_002bd64c lang=c99 */
/* Clone of src/eboot/FUN_002ade24.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_0001100c();

/* True when the two 16-byte blocks are equal. */
bool FUN_002bd64c(u32 a,u32 b)
{
  int diff;
  
  diff = FUN_0001100c(a,b,0x10);
  return diff == 0;
}
