/* HSTMATCH module=hstp_trans_main.prx start=0x002637c0 end=0x00263808 symbol=FUN_002637c0 lang=c99 */
/* Clone of src/eboot/FUN_0025346c_0025346c.c (hstclone.py tag u5cr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: reversed the nested mode and u8 arms and made the u8 unsigned; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_001e7db4();

void FUN_002637c0(int param_1,int param_2)
{
  u32 uVar1;
  
  if (param_2 != 0) {
    if (*(unsigned char *)(param_1 + 0x34) != 0) {
      uVar1 = 2;
    }
    else {
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0;
  }
  uVar1 = FUN_001e7db4(param_1 + 0x3c,uVar1);
  *(u32 *)(param_1 + 0x38) = uVar1;
}
