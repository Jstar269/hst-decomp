/* HSTMATCH module=hstp_trans_main.prx start=0x001b1df0 end=0x001b1e70 symbol=FUN_001b1df0 lang=c99 */
/* Clone of src/eboot/FUN_001a4824.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag q4) corrected by hand: the range check made unsigned; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_001772d4();
extern int FUN_00177720();

u32 FUN_001b1df0(u32 param_1,int param_2)
{
  int iVar1;
  u8 *pbVar2;
  int iVar3;
  
  iVar1 = FUN_001772d4();
  iVar3 = 0;
  if (0 < iVar1) {
    do {
      if ((iVar3 == param_2) && (pbVar2 = (u8 *)FUN_00177720(iVar3), (unsigned int)(*pbVar2 - 4) < 2)) {
        return 1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  return 0;
}
