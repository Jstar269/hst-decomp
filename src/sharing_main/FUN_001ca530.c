/* HSTMATCH module=hstp_trans_main.prx start=0x001ca530 end=0x001ca5c8 symbol=FUN_001ca530 lang=c99 */
/* Clone of src/eboot/FUN_001bc748.c (hstclone.py tag s10172123g4r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: inverted if/else branches; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 * FUN_000114c0();

void FUN_001ca530(u32 *param_1, int param_2)
{
  if (param_2 != 0) {
    *param_1 = 9999;
    param_1[1] = 9999;
    param_1[2] = 0xf0000000;
    param_1[3] = 0xf0000000;
    param_1[4] = 0xf0000000;
    param_1[5] = 0xf0000000;
    param_1[6] = 0xf0000000;
    param_1[7] = 0xf0000000;
    param_1[8] = 0xf0000000;
    param_1[9] = 0xf0000000;
    param_1[10] = 0xf0000000;
    param_1[0x18] = 0xf0000000;
    param_1[0x19] = 0xf0000000;
    param_1[0xb] = 0xf0000000;
    param_1[0xc] = 0xf0000000;
    param_1[0xd] = 0;
    param_1[0xe] = 0;
    param_1[0xf] = 0;
    param_1[0x10] = 0;
    param_1[0x11] = 0xf0000000;
    param_1[0x12] = 0xf0000000;
    param_1[0x13] = 9999;
    param_1[0x14] = 9999;
    param_1[0x15] = 9999;
    param_1[0x16] = 9999;
    param_1[0x17] = 9999;
  }
  else {
    FUN_000114c0(param_1, 0, 0xa0);
  }
}
