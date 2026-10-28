/* HSTMATCH module=EBOOT.BIN start=0x0023a848 end=0x0023a900 symbol=FUN_0023a848 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: wrote the threshold as count >= 2 to match the retail comparison result register; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_002cfc8c;
extern void FUN_002395f8();
extern void FUN_00239a7c();
extern void FUN_0023c2ac();

void FUN_0023a848(int param_1)
{
  FUN_002395f8();
  if (*(int *)(param_1 + 0x3c) >= 2) {
    FUN_00239a7c(param_1);
  }
  FUN_0023c2ac(param_1 + 0x50);
  *(u32 *)(param_1 + 0x17dc) = *(u32 *)(param_1 + 0x17d8);
  *(u32 *)(param_1 + 0x17f0) = *(u32 *)(param_1 + 0x17ec);
  *(u32 *)(param_1 + 0x17d8) = *(u32 *)(param_1 + 0x17d4);
  *(u32 *)(param_1 + 0x17ec) = *(u32 *)(param_1 + 0x17e8);
  *(u32 *)(param_1 + 0x17d4) = *(u32 *)(param_1 + 0x17d0);
  *(u32 *)(param_1 + 0x17e8) = *(u32 *)(param_1 + 0x17e4);
  *(u32 *)(param_1 + 0x17d0) = *(u32 *)(param_1 + 0x17cc);
  *(u32 *)(param_1 + 0x17e4) = *(u32 *)(param_1 + 0x17e0);
  *(int *)(param_1 + 0x17cc) = ((int)*(char *)(DAT_002cfc8c + 0x89) << 0x1e) >> 0x1e;
  *(int *)(param_1 + 0x17e0) = ((int)*(char *)(DAT_002cfc8c + 0x89) << 0x1a) >> 0x1e;
}
