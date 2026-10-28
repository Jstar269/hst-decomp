/* HSTMATCH module=hstp_trans_main.prx start=0x001592b0 end=0x00159324 symbol=FUN_001592b0 lang=c99 */
/* Clone of src/eboot/FUN_0014d788.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag q4) corrected by hand: the 4-bit field extracted as (x >> 12) & 0xf; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b15f8;
extern u8 DAT_003b16d8;
extern u32 FUN_0015b028();
extern u16 FUN_0015b050();

u32 * FUN_001592b0(u32 *param_1,u32 param_2)
{
  u32 uVar1;
  u32 uVar2;
  
  *param_1 = (unsigned int)(&DAT_003b16d8);
  *(u8 *)(param_1 + 1) = 0;
  *param_1 = (unsigned int)(&DAT_003b15f8);
  uVar1 = FUN_0015b050(param_2);
  param_1[2] = (uVar1 >> 0xc) & 0xf;
  param_1[3] = uVar1 & 0xfff;
  uVar2 = FUN_0015b028(param_2);
  param_1[4] = uVar2;
  return param_1;
}
