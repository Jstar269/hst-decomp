/* HSTMATCH module=hstp_trans_main.prx start=0x000df814 end=0x000df888 symbol=FUN_000df814 lang=c99 */
/* Clone of src/eboot/FUN_000db7f4.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag p128a) corrected by hand: the two odd-address globals typed as bytes; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003eabd3;
extern u8 DAT_003eacf3;
extern u32 * FUN_000114c0();

void FUN_000df814(int param_1)
{
  FUN_000114c0((u32 *)(param_1 + 0xd8),0,0x30);
  *(u32 *)(param_1 + 0xd0) = (u32)DAT_003eabd3;
  *(u32 *)(param_1 + 0xc4) = 0;
  *(u32 *)(param_1 + 0xb8) = 0;
  *(u32 *)(param_1 + 0xd4) = (u32)DAT_003eacf3;
  *(u32 *)(param_1 + 200) = 0;
  *(u32 *)(param_1 + 0xbc) = 0;
  *(u32 *)(param_1 + 0x48) = 1;
  *(u32 *)(param_1 + 0x4c) = 1;
  *(u32 *)(param_1 + 0x50) = 0;
  *(u32 *)(param_1 + 0x54) = 0;
  *(u32 *)(param_1 + 0x58) = 1;
  *(u8 *)(param_1 + 0x108) = 0;
}
