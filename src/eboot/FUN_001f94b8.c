/* HSTMATCH module=EBOOT.BIN start=0x001f94b8 end=0x001f9518 symbol=FUN_001f94b8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed float and pointer arguments and replaced the numeric address with DAT_0034179c; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_00331b84;
extern u32 DAT_0034179c;
extern void FUN_0006391c(float,u32,int);
extern void FUN_001b3ea4(float,u32 *);
extern void FUN_001fb928();

void FUN_001f94b8(int param_1)
{
  FUN_0006391c(65535.0f,DAT_00331b84,0xf);
  FUN_001b3ea4(0.5f,&DAT_0034179c);
  FUN_001fb928(param_1 + 0x3c,0x11,1);
}
