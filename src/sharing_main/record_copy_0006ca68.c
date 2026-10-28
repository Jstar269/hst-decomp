/* HSTMATCH module=hstp_trans_main.prx start=0x0006ca68 end=0x0006cb54 symbol=FUN_0006ca68 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: typed floating record members as float while preserving adjacent integer fields; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_0004c898();
extern u32 * FUN_0005931c();

u32 * FUN_0006ca68(u32 *param_1,u32 *param_2)
{
  *param_1 = *param_2;
  FUN_0005931c(param_1 + 4,param_2 + 4);
  FUN_0004c898(param_1 + 0x14,param_2 + 0x14);
  FUN_0004c898(param_1 + 0x18,param_2 + 0x18);
  ((float *)param_1)[0x1c] = ((float *)param_2)[0x1c];
  ((float *)param_1)[0x1d] = ((float *)param_2)[0x1d];
  ((float *)param_1)[0x1e] = ((float *)param_2)[0x1e];
  param_1[0x1f] = param_2[0x1f];
  param_1[0x20] = param_2[0x20];
  ((float *)param_1)[0x21] = ((float *)param_2)[0x21];
  ((float *)param_1)[0x22] = ((float *)param_2)[0x22];
  ((float *)param_1)[0x23] = ((float *)param_2)[0x23];
  ((float *)param_1)[0x24] = ((float *)param_2)[0x24];
  ((float *)param_1)[0x25] = ((float *)param_2)[0x25];
  ((float *)param_1)[0x26] = ((float *)param_2)[0x26];
  ((float *)param_1)[0x27] = ((float *)param_2)[0x27];
  ((float *)param_1)[0x28] = ((float *)param_2)[0x28];
  *(u8 *)(param_1 + 0x29) = *(u8 *)(param_2 + 0x29);
  *(u8 *)((int)param_1 + 0xa5) = *(u8 *)((int)param_2 + 0xa5);
  *(u8 *)((int)param_1 + 0xa6) = *(u8 *)((int)param_2 + 0xa6);
  *(u8 *)((int)param_1 + 0xa7) = *(u8 *)((int)param_2 + 0xa7);
  *(u8 *)(param_1 + 0x2a) = *(u8 *)(param_2 + 0x2a);
  return param_1;
}
