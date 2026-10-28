/* HSTMATCH module=hstp_trans_main.prx start=0x000c4cc4 end=0x000c4d4c symbol=FUN_000c4cc4 lang=c99 */
/* Clone of src/eboot/FUN_000c1624.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_002d0310;
extern u8 DAT_0037c3ac;
extern u8 DAT_0037c3bc;
extern u8 DAT_0037c3c4;
extern char DAT_0037c3b4[];
extern u32 * FUN_00011090();
extern u32 * FUN_000114c0();

void FUN_000c4cc4(int param_1)
{
  if (param_1 != 0) {
    FUN_000114c0(param_1,0,0x4c);
    FUN_00011090(param_1 + 0x20,&DAT_002d0310,0x10);
    *(u8 **)(param_1 + 0x30) = &DAT_0037c3ac;
    *(char **)(param_1 + 0x34) = DAT_0037c3b4;
    *(u8 **)(param_1 + 0x38) = &DAT_0037c3bc;
    *(u8 **)(param_1 + 0x3c) = &DAT_0037c3c4;
    *(u8 **)(param_1 + 0x40) = &DAT_0037c3c4;
    *(u32 *)(param_1 + 0x44) = 1;
    *(u8 *)(param_1 + 0x48) = 1;
  }
}
