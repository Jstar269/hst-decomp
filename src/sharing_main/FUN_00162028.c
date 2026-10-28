/* HSTMATCH module=hstp_trans_main.prx start=0x00162028 end=0x00162070 symbol=FUN_00162028 lang=c99 */
/* Clone of src/eboot/FUN_00155bb0.c (hstclone.py tag c34): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: the flag global typed as a u8 and the object address Ghidra dropped from the call restored; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003e9630;
extern u8 DAT_00384048;
extern u8 DAT_003eaad8;
extern void FUN_00158b2c();
extern void FUN_0015bb68();
extern void FUN_001c21b0();

u32 FUN_00162028(u32 param_1,int param_2)
{
  if (DAT_003e9630 != '\0') {
    FUN_00158b2c(param_2);
    FUN_0015bb68(&DAT_00384048);
  }
  FUN_001c21b0((int *)&DAT_003eaad8);
  return 0;
}
