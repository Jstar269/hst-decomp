/* HSTMATCH module=EBOOT.BIN start=0x000ae68c end=0x000ae774 symbol=FUN_000ae68c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: control flow, byte and float fields, and bit tests; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_003386b0;
extern unsigned char DAT_003386b8;
extern void FUN_000a0410();

void FUN_000ae68c(int param_1,int param_2)
{
  if (*(int *)(DAT_003386b0 + 0x3c) != 7) {
    int bVar2 = DAT_003386b8 != 0;
    if (bVar2) {
      bVar2 = *(u8 *)(param_1 + 0x1b4) != 0;
    }
    if (bVar2 == 0) {
      return;
    }
  }
  *(int *)(param_1 + 0x41c) = (int)*(short *)(param_2 + 0x20);
  *(int *)(param_1 + 0x4e4) = ((int)*(char *)(param_2 + 0x22) << 0x1d) >> 0x1d;
  *(int *)(param_1 + 0x4e8) = ((int)*(char *)(param_2 + 0x22) << 0x18) >> 0x1b;
  *(bool *)(param_1 + 0x4cf) = ((int)*(char *)(param_2 + 0x23) << 0x1e) >> 0x1e != 0;
  *(bool *)(param_1 + 0x4d8) = (((int)*(char *)(param_2 + 0x23) << 0x1d) >> 31) != 0;
  *(bool *)(param_1 + 0x4d9) = (((int)*(char *)(param_2 + 0x23) << 0x1c) >> 31) != 0;
  *(bool *)(param_1 + 0x4da) = (((int)*(char *)(param_2 + 0x23) << 0x1b) >> 31) != 0;
  *(int *)(param_1 + 0x4dc) = ((int)*(char *)(param_2 + 0x23) << 0x18) >> 0x1d;
  *(float *)(param_1 + 0x43c) = *(float *)(param_2 + 0x24);
  FUN_000a0410(param_1,*(u32 *)(param_1 + 0x4dc));
}
