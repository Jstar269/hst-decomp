/* HSTMATCH module=EBOOT.BIN start=0x000f21a4 end=0x000f21f0 symbol=FUN_000f21a4 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000f21f0();
extern void FUN_0010f5d4();

void FUN_000f21a4(int param_1)
{
  if (*(u8 *)(param_1 + 0x84) != '\0') {
    *(u32 *)(param_1 + 0x78) = 0;
    *(u32 *)(param_1 + 0x7c) = 0;
    *(u32 *)(param_1 + 0x80) = 1;
    FUN_0010f5d4(*(u32 *)(param_1 + 0x68),*(u32 *)(param_1 + 0x78));
    FUN_000f21f0(param_1);
  }
}
