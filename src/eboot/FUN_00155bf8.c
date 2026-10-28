/* HSTMATCH module=EBOOT.BIN start=0x00155bf8 end=0x00155c40 symbol=FUN_00155bf8 lang=c99 */
/* Clone of src/eboot/FUN_00155bb0.c (hstclone.py tag c33): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: the flag global typed as a u8 and the object address Ghidra dropped from the call restored; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003402f0;
extern u8 DAT_002dcb84;
extern u8 DAT_0034179c;
extern void FUN_0014d044();
extern void FUN_0014fd94();
extern void FUN_001b47d8();

u32 FUN_00155bf8(u32 param_1,int param_2)
{
  if (DAT_003402f0 != '\0') {
    FUN_0014d044(param_2);
    FUN_0014fd94(&DAT_002dcb84);
  }
  FUN_001b47d8((int *)&DAT_0034179c);
  return 0;
}
