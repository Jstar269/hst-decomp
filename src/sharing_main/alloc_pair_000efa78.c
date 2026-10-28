/* HSTMATCH module=hstp_trans_main.prx start=0x000efa78 end=0x000efafc symbol=FUN_000efa78 lang=c99 */
/* Clone of src/eboot/alloc_pair_000ea868.c (hstclone.py tag c20s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2/v0) corrected by hand: merged each allocation store and restored the final constructor argument; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_00000bcc();
extern u32 * FUN_0005b814(u32 *, int, int, int, int, int);

void FUN_000efa78(int param_1)
{
  u32 *puVar1;
  
  puVar1 = (u32 *)FUN_00000bcc(0x70);
  if (puVar1 != (u32 *)0x0)
    puVar1 = FUN_0005b814(puVar1,1,4,1,1,0);
  *(u32 **)(param_1 + 0x40) = puVar1;
  puVar1 = (u32 *)FUN_00000bcc(0x70);
  if (puVar1 != (u32 *)0x0)
    puVar1 = FUN_0005b814(puVar1,1,4,1,1,0);
  *(u32 **)(param_1 + 0x44) = puVar1;
}
