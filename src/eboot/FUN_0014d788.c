/* HSTMATCH module=EBOOT.BIN start=0x0014d788 end=0x0014d7fc symbol=FUN_0014d788 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag q4) corrected by hand: the 4-bit field extracted as (x >> 12) & 0xf; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0030832c;
extern u8 DAT_0030840c;
extern u32 FUN_0014f028();
extern u16 FUN_0014f050();

u32 * FUN_0014d788(u32 *param_1,u32 param_2)
{
  u32 uVar1;
  u32 uVar2;
  
  *param_1 = (unsigned int)(&DAT_0030840c);
  *(u8 *)(param_1 + 1) = 0;
  *param_1 = (unsigned int)(&DAT_0030832c);
  uVar1 = FUN_0014f050(param_2);
  param_1[2] = (uVar1 >> 0xc) & 0xf;
  param_1[3] = uVar1 & 0xfff;
  uVar2 = FUN_0014f028(param_2);
  param_1[4] = uVar2;
  return param_1;
}
