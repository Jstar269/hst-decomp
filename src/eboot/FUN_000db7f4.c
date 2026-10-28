/* HSTMATCH module=EBOOT.BIN start=0x000db7f4 end=0x000db868 symbol=FUN_000db7f4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p128a) corrected by hand: the two odd-address globals typed as bytes; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0034189b;
extern u8 DAT_003419bb;
extern u32 * FUN_000114c0();

void FUN_000db7f4(int param_1)
{
  FUN_000114c0((u32 *)(param_1 + 0xd8),0,0x30);
  *(u32 *)(param_1 + 0xd0) = (u32)DAT_0034189b;
  *(u32 *)(param_1 + 0xc4) = 0;
  *(u32 *)(param_1 + 0xb8) = 0;
  *(u32 *)(param_1 + 0xd4) = (u32)DAT_003419bb;
  *(u32 *)(param_1 + 200) = 0;
  *(u32 *)(param_1 + 0xbc) = 0;
  *(u32 *)(param_1 + 0x48) = 1;
  *(u32 *)(param_1 + 0x4c) = 1;
  *(u32 *)(param_1 + 0x50) = 0;
  *(u32 *)(param_1 + 0x54) = 0;
  *(u32 *)(param_1 + 0x58) = 1;
  *(u8 *)(param_1 + 0x108) = 0;
}
