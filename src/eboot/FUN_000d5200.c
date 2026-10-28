/* HSTMATCH module=EBOOT.BIN start=0x000d5200 end=0x000d5244 symbol=FUN_000d5200 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0030753c;
extern int FUN_00000bcc();

void FUN_000d5200(int param_1)
{
  u32 *puVar1;
  
  puVar1 = (u32 *)FUN_00000bcc(8);
  if (puVar1 != (u32 *)0x0) {
    *puVar1 = (unsigned int)(&DAT_0030753c);
    puVar1[1] = *(u32 *)(param_1 + 4);
  }
}
