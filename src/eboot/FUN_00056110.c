/* HSTMATCH module=EBOOT.BIN start=0x00056110 end=0x00056198 symbol=FUN_00056110 lang=c99 */
/* Clone of src/sharing_main/FUN_00056d24.c (hstclone.py tag u4r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0c) corrected by hand: typed the first helper as an object receiver and stored the allocated pointer after the guarded initialization; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_00000bcc();
extern u32 FUN_00055eac();
extern void FUN_000562b8(u32 *);

u32 * FUN_00056110(u32 *param_1,u32 param_2,u32 param_3)
{
  u32 *puVar1;
  
  FUN_000562b8(param_1);
  puVar1 = (u32 *)FUN_00000bcc(0x10);
  if (puVar1 != (u32 *)0x0) {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    FUN_00055eac(puVar1,param_2,param_3);
  }
  *param_1 = (unsigned int)puVar1;
  *(u8 *)(param_1 + 2) = 1;
  return param_1;
}
