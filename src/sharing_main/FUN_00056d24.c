/* HSTMATCH module=hstp_trans_main.prx start=0x00056d24 end=0x00056dac symbol=FUN_00056d24 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0c) corrected by hand: typed the first helper as an object receiver and stored the allocated pointer after the guarded initialization; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_00000bcc();
extern u32 FUN_00056a58();
extern void FUN_00056ecc(u32 *);

u32 * FUN_00056d24(u32 *param_1,u32 param_2,u32 param_3)
{
  u32 *puVar1;
  
  FUN_00056ecc(param_1);
  puVar1 = (u32 *)FUN_00000bcc(0x10);
  if (puVar1 != (u32 *)0x0) {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[2] = 0;
    puVar1[3] = 0;
    FUN_00056a58(puVar1,param_2,param_3);
  }
  *param_1 = (unsigned int)puVar1;
  *(u8 *)(param_1 + 2) = 1;
  return param_1;
}
