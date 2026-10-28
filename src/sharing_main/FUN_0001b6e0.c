/* HSTMATCH module=hstp_trans_main.prx start=0x0001b6e0 end=0x0001b710 symbol=FUN_0001b6e0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003b7ea0;
extern void FUN_0001b5a8();
extern void FUN_002c7718();

u32 FUN_0001b6e0(void)
{
  FUN_0001b5a8();
  DAT_003b7ea0 = 0;
  FUN_002c7718(0);
  return 0;
}
