/* HSTMATCH module=hstp_trans_main.prx start=0x00057ad8 end=0x00057b2c symbol=FUN_00057ad8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: typed the helper result as unsigned char and reordered the callback arms; exact match verified; names and types await human review. */
#include "hst/types.h"

extern bool FUN_00055c68();
extern void FUN_00057b58();
extern void FUN_00057bdc();

unsigned char FUN_00057ad8(u32 param_1)
{
  unsigned char cVar1;
  
  cVar1 = FUN_00055c68();
  if (cVar1 != 0) {
    FUN_00057b58(param_1);
  } else {
    FUN_00057bdc(param_1);
  }
  return cVar1;
}
