/* HSTMATCH module=hstp_trans_main.prx start=0x001c0454 end=0x001c04c4 symbol=FUN_001c0454 lang=c99 */
/* Clone of src/eboot/if_else_two_calls_001b23c0.c (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: swapped if/else order (param_2 != 0 first); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00063190();

void FUN_001c0454(u32 param_1,int param_2)
{
  if (param_2 != 0) {
    FUN_00063190(3,0x40,0x40,0xf);
    FUN_00063190(2,0,0,3);
  }
  else {
    FUN_00063190(3,0x80,0x80,0xf);
    FUN_00063190(2,0x80,0x80,3);
  }
}
