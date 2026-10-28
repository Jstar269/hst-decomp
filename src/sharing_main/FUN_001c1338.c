/* HSTMATCH module=hstp_trans_main.prx start=0x001c1338 end=0x001c1394 symbol=FUN_001c1338 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag sh2); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001bdec0();
extern void FUN_001bdfd8();

void FUN_001c1338(u32 *param_1)
{
  u32 uVar1;
  
  uVar1 = *param_1;
  FUN_001bdfd8(uVar1,0);
  FUN_001bdec0(uVar1,3);
  FUN_001bdec0(uVar1,2);
  FUN_001bdec0(uVar1,1);
  FUN_001bdec0(uVar1,0);
}
