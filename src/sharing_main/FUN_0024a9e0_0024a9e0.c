/* HSTMATCH module=hstp_trans_main.prx start=0x0024a9e0 end=0x0024aa98 symbol=FUN_0024a9e0 lang=c99 */
/* Clone of src/eboot/FUN_0023a848_0023a848.c (hstclone.py tag u4r4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: wrote the threshold as count >= 2 to match the retail comparison result register; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_003751d4;
extern void FUN_00249790();
extern void FUN_00249c14();
extern void FUN_0024c444();

void FUN_0024a9e0(int param_1)
{
  FUN_00249790();
  if (*(int *)(param_1 + 0x3c) >= 2) {
    FUN_00249c14(param_1);
  }
  FUN_0024c444(param_1 + 0x50);
  *(u32 *)(param_1 + 0x17dc) = *(u32 *)(param_1 + 0x17d8);
  *(u32 *)(param_1 + 0x17f0) = *(u32 *)(param_1 + 0x17ec);
  *(u32 *)(param_1 + 0x17d8) = *(u32 *)(param_1 + 0x17d4);
  *(u32 *)(param_1 + 0x17ec) = *(u32 *)(param_1 + 0x17e8);
  *(u32 *)(param_1 + 0x17d4) = *(u32 *)(param_1 + 0x17d0);
  *(u32 *)(param_1 + 0x17e8) = *(u32 *)(param_1 + 0x17e4);
  *(u32 *)(param_1 + 0x17d0) = *(u32 *)(param_1 + 0x17cc);
  *(u32 *)(param_1 + 0x17e4) = *(u32 *)(param_1 + 0x17e0);
  *(int *)(param_1 + 0x17cc) = ((int)*(char *)(DAT_003751d4 + 0x89) << 0x1e) >> 0x1e;
  *(int *)(param_1 + 0x17e0) = ((int)*(char *)(DAT_003751d4 + 0x89) << 0x1a) >> 0x1e;
}
