/* HSTMATCH module=hstp_trans_main.prx start=0x000f786c end=0x000f78b8 symbol=FUN_000f786c lang=c99 */
/* Clone of src/eboot/FUN_000f21a4.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000f78b8();
extern void FUN_00116fd4();

void FUN_000f786c(int param_1)
{
  if (*(u8 *)(param_1 + 0x84) != '\0') {
    *(u32 *)(param_1 + 0x78) = 0;
    *(u32 *)(param_1 + 0x7c) = 0;
    *(u32 *)(param_1 + 0x80) = 1;
    FUN_00116fd4(*(u32 *)(param_1 + 0x68),*(u32 *)(param_1 + 0x78));
    FUN_000f78b8(param_1);
  }
}
