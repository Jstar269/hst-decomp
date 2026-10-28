/* HSTMATCH module=EBOOT.BIN start=0x000c1534 end=0x000c15e0 symbol=FUN_000c1534 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_000149a8();

void FUN_000c1534(int param_1)
{
  FUN_000149a8(param_1 + 0x114,*(u32 *)(param_1 + 0x80));
  FUN_000149a8(param_1 + 0x194,*(u32 *)(param_1 + 0x84));
  FUN_000149a8(param_1 + 0x214,*(u32 *)(param_1 + 0x88));
  *(char *)(param_1 + 0x614) = (char)*(u32 *)(param_1 + 0x8c);
  *(u32 *)(param_1 + 0x618) = *(u32 *)(param_1 + 0x48);
  *(u32 *)(param_1 + 0x61c) = *(u32 *)(param_1 + 0x58);
  *(u32 *)(param_1 + 0x620) = *(u32 *)(param_1 + 0x58);
  *(u32 *)(param_1 + 0x638) = *(u32 *)(param_1 + 0x50);
  *(u32 *)(param_1 + 0x63c) = *(u32 *)(param_1 + 0x60);
  *(u32 *)(param_1 + 0x640) = *(u32 *)(param_1 + 0x60);
  *(u32 *)(param_1 + 0x628) = *(u32 *)(param_1 + 0x4c);
  *(u32 *)(param_1 + 0x62c) = *(u32 *)(param_1 + 0x5c);
  *(u32 *)(param_1 + 0x630) = *(u32 *)(param_1 + 0x5c);
  *(u32 *)(param_1 + 0x648) = *(u32 *)(param_1 + 0x54);
  *(u32 *)(param_1 + 0x64c) = *(u32 *)(param_1 + 100);
  *(u32 *)(param_1 + 0x650) = *(u32 *)(param_1 + 100);
}
