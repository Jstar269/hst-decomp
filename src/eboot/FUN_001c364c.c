/* HSTMATCH module=EBOOT.BIN start=0x001c364c end=0x001c36d8 symbol=FUN_001c364c lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag s256a); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003415d4;
extern void FUN_0015d46c();
extern void FUN_001905b8();
extern void FUN_001ca8f0();
extern void FUN_001cd3d8();
extern void FUN_001cd88c();

void FUN_001c364c(int param_1)
{
  if (*(int *)(param_1 + 8) == 0x1e) {
    if (*(int *)(param_1 + 0xf8) == 1) {
      FUN_0015d46c();
    }
    else {
      FUN_001ca8f0(*(u32 *)(param_1 + 0x18));
      *(u32 *)(param_1 + 0xe8) = 1;
      *(u8 *)(param_1 + 0xf0) = 0;
      FUN_001905b8(DAT_003415d4,3);
      FUN_001cd88c(param_1,8,1);
      FUN_001cd3d8(*(u32 *)(param_1 + 0x18));
    }
  }
}
