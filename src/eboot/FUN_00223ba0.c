/* HSTMATCH module=EBOOT.BIN start=0x00223ba0 end=0x00223c04 symbol=FUN_00223ba0 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s128a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00223db0();

void FUN_00223ba0(int param_1)
{
  FUN_00223db0();
  *(u32 *)(param_1 + 0x78) = 0xffffffff;
  *(u32 *)(param_1 + 0x7c) = 0;
  *(u32 *)(param_1 + 0x84) = 0;
  *(u32 *)(param_1 + 0x8c) = 0;
  *(u32 *)(param_1 + 0x94) = 0;
  *(u32 *)(param_1 + 0x9c) = 0;
  *(u8 *)(param_1 + 0xa4) = 0;
  *(u8 *)(param_1 + 0xa6) = 0;
  *(u32 *)(param_1 + 0x80) = 0;
  *(u32 *)(param_1 + 0x88) = 0;
  *(u32 *)(param_1 + 0x90) = 0;
  *(u32 *)(param_1 + 0x98) = 0;
  *(u32 *)(param_1 + 0xa0) = 0;
  *(u8 *)(param_1 + 0xa5) = 0;
  *(u8 *)(param_1 + 0xa7) = 0;
}
