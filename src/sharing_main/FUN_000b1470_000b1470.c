/* HSTMATCH module=hstp_trans_main.prx start=0x000b1470 end=0x000b1558 symbol=FUN_000b1470 lang=c99 */
/* Clone of src/eboot/FUN_000ae68c_000ae68c.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: control flow, u8 and float fields, and bit tests; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_003e19f0;
extern unsigned char DAT_003e19f8;
extern void FUN_000a2a1c();

void FUN_000b1470(int param_1,int param_2)
{
  if (*(int *)(DAT_003e19f0 + 0x3c) != 7) {
    int bVar2 = DAT_003e19f8 != 0;
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
  FUN_000a2a1c(param_1,*(u32 *)(param_1 + 0x4dc));
}
