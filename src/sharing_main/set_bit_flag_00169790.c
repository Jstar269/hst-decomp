/* HSTMATCH module=hstp_trans_main.prx start=0x00169790 end=0x001697ec symbol=FUN_00169790 lang=c99 */
/* Clone of src/eboot/set_bit_flag_0015d1e8.c (hstclone.py tag c47): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: the shifted bit is a signed char local OR-ed into the u8 field (seb/andi, no shift mask); exact match verified; names and types await human review. */
#include "hst/types.h"
typedef int code();

extern code * FUN_0023ce60();

void FUN_00169790(u32 param_1)
{
  int iVar1;
  signed char m;
  iVar1 = (int)(FUN_0023ce60());
  m = 1 << param_1;
  *(u8 *)(iVar1 + 0xf0) |= m;
  if (param_1 == 0) {
    *(u8 *)(iVar1 + 0x13c) = 1;
  }
  else if (param_1 == 2) {
    *(u8 *)(iVar1 + 0x13d) = 1;
  }
}
