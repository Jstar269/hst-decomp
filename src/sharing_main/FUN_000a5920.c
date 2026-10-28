/* HSTMATCH module=hstp_trans_main.prx start=0x000a5920 end=0x000a5968 symbol=FUN_000a5920 lang=c99 */
/* Clone of src/eboot/FUN_000a31b4.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_000b6e80();
extern float FUN_00170550();

float FUN_000a5920(int param_1)
{
  u32 uVar1;
  float fVar2;
  
  uVar1 = FUN_000b6e80();
  fVar2 = (float)FUN_00170550(uVar1,*(u32 *)(param_1 + 0x154));
  return (fVar2 - 1.0f) / 9.0f;
}
