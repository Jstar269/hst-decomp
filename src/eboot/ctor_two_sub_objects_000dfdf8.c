/* HSTMATCH module=EBOOT.BIN start=0x000dfdf8 end=0x000dfec0 symbol=FUN_000dfdf8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: sub-object allocation is 'p = alloc(); if (p) p = ctor(p, 1, 4, 1, 1, 0); m = p;' with the dropped sixth argument; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003076d4;
extern int FUN_00000bcc();
extern u32 * FUN_0001f06c();
extern u32 * FUN_0005aa44();

u32 * FUN_000dfdf8(u32 *param_1,u32 param_2)
{
  u32 *puVar1;
  
  FUN_0001f06c(param_1);
  *param_1 = (unsigned int)(&DAT_003076d4);
  param_1[0xf] = param_2;
  puVar1 = (u32 *)FUN_00000bcc(0x70);
  if (puVar1 != (u32 *)0x0) {
    puVar1 = FUN_0005aa44(puVar1,1,4,1,1,0);
  }
  param_1[0x1c] = (unsigned int)(puVar1);
  puVar1 = (u32 *)FUN_00000bcc(0x70);
  if (puVar1 != (u32 *)0x0) {
    puVar1 = FUN_0005aa44(puVar1,1,4,1,1,0);
  }
  param_1[0x1d] = (unsigned int)(puVar1);
  param_1[0x14] = 0x3f800000;
  param_1[0x18] = 0x43000000;
  param_1[0x19] = 0x43000000;
  param_1[0x1a] = 0x43000000;
  param_1[0x1b] = 0x42800000;
  param_1[0x1e] = 0;
  return param_1;
}
