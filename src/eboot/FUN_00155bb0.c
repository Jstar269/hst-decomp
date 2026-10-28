/* HSTMATCH module=EBOOT.BIN start=0x00155bb0 end=0x00155bf8 symbol=FUN_00155bb0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: the flag global typed as a byte and the object address Ghidra dropped from the call restored; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003402f0;
extern u8 DAT_002dcb78;
extern u8 DAT_0034179c;
extern void FUN_0014d044();
extern void FUN_0014fd94();
extern void FUN_001b46bc();

u32 FUN_00155bb0(u32 param_1,int param_2)
{
  if (DAT_003402f0 != '\0') {
    FUN_0014d044(param_2);
    FUN_0014fd94(&DAT_002dcb78);
  }
  FUN_001b46bc((int *)&DAT_0034179c);
  return 0;
}
