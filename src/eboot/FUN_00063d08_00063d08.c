/* HSTMATCH module=EBOOT.BIN start=0x00063d08 end=0x00063dc8 symbol=FUN_00063d08 lang=c99 */
/* Clone of src/sharing_main/FUN_00064bcc_00064bcc.c (hstclone.py tag u1r2e): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag sh2/v0) corrected by hand: restored the object and float parameter positions from the EABI register evidence; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000513a0();

void FUN_00063d08(int param_1,float param_2,int param_3,float param_4)
{
  *(u32 *)(param_1 + 0x20) = 0x3f800000;
  *(u32 *)(param_1 + 0x24) = 0x3f800000;
  *(u32 *)(param_1 + 0x28) = 0x3f800000;
  *(u32 *)(param_1 + 0x2c) = 0x3f800000;
  *(u32 *)(param_1 + 0x30) = 0x3f800000;
  *(u32 *)(param_1 + 0x34) = 0x3f800000;
  *(u32 *)(param_1 + 0x38) = 0x3f800000;
  *(u32 *)(param_1 + 0x3c) = 0;
  *(float *)(param_1 + 8) = (float)param_3;
  *(float *)(param_1 + 0xc) = (float)param_3;
  *(u32 *)(param_1 + 0x10) = 0xbf800000;
  FUN_000513a0(*(u32 *)(param_1 + 4),0);
  *(u8 *)(param_1 + 0x40) = 1;
  *(u8 *)(param_1 + 0x41) = 0;
  if (param_4 < 0.0f) {
    param_4 = 4000.0f;
  }
  *(float *)(param_1 + 0x44) = param_4;
  *(u8 *)(param_1 + 0x50) = 0;
  *(u8 *)(param_1 + 0x51) = 0;
  *(u8 *)(param_1 + 0x52) = 1;
  *(u8 *)(param_1 + 0x53) = 1;
  *(float *)(param_1 + 0x54) = param_2;
}
