/* HSTMATCH module=EBOOT.BIN start=0x000c1624 end=0x000c16ac symbol=FUN_000c1624 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002c00e8;
extern u8 DAT_002d5a5c;
extern u8 DAT_002d5a6c;
extern u8 DAT_002d5a74;
extern char DAT_002d5a64[];
extern u32 * FUN_00011090();
extern u32 * FUN_000114c0();

void FUN_000c1624(int param_1)
{
  if (param_1 != 0) {
    FUN_000114c0(param_1,0,0x4c);
    FUN_00011090(param_1 + 0x20,&DAT_002c00e8,0x10);
    *(u8 **)(param_1 + 0x30) = &DAT_002d5a5c;
    *(char **)(param_1 + 0x34) = DAT_002d5a64;
    *(u8 **)(param_1 + 0x38) = &DAT_002d5a6c;
    *(u8 **)(param_1 + 0x3c) = &DAT_002d5a74;
    *(u8 **)(param_1 + 0x40) = &DAT_002d5a74;
    *(u32 *)(param_1 + 0x44) = 1;
    *(u8 *)(param_1 + 0x48) = 1;
  }
}
