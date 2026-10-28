/* HSTMATCH module=EBOOT.BIN start=0x000ea868 end=0x000ea8ec symbol=FUN_000ea868 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2/v0) corrected by hand: merged each allocation store and restored the final constructor argument; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_00000bcc();
extern u32 * FUN_0005aa44(u32 *, int, int, int, int, int);

void FUN_000ea868(int param_1)
{
  u32 *puVar1;
  
  puVar1 = (u32 *)FUN_00000bcc(0x70);
  if (puVar1 != (u32 *)0x0)
    puVar1 = FUN_0005aa44(puVar1,1,4,1,1,0);
  *(u32 **)(param_1 + 0x40) = puVar1;
  puVar1 = (u32 *)FUN_00000bcc(0x70);
  if (puVar1 != (u32 *)0x0)
    puVar1 = FUN_0005aa44(puVar1,1,4,1,1,0);
  *(u32 **)(param_1 + 0x44) = puVar1;
}
