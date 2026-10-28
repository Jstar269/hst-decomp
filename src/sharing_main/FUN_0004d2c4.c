/* HSTMATCH module=hstp_trans_main.prx start=0x0004d2c4 end=0x0004d31c symbol=FUN_0004d2c4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b3e6c;
extern u8 DAT_003b8ec5;
extern u32 DAT_003ba498;
extern void FUN_0001c340();
extern int FUN_002c7518();

u32 FUN_0004d2c4(void)
{
  u32 uVar1;
  
  if (DAT_003ba498 == 0) {
    if (DAT_003b8ec5 != '\0') {
      FUN_0001c340((int)&DAT_003b3e6c);
      return 0;
    }
  }
  else {
    DAT_003ba498 = DAT_003ba498 + -1;
  }
  uVar1 = FUN_002c7518();
  return uVar1;
}
