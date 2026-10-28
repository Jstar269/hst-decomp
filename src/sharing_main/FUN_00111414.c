/* HSTMATCH module=hstp_trans_main.prx start=0x00111414 end=0x00111474 symbol=FUN_00111414 lang=c99 */
/* Clone of src/eboot/FUN_0010b308.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00111474();
extern void FUN_00120e84();

void FUN_00111414(int param_1)
{
  *(u32 *)(param_1 + 0xd4) = 0;
  *(u32 *)(param_1 + 0xd8) = 0;
  *(u32 *)(param_1 + 0x110) = 0;
  *(u8 *)(param_1 + 0x114) = 0;
  *(u32 *)(param_1 + 0x118) = 0;
  if (*(u32 *)(param_1 + 0x128) < 4) {
    FUN_00120e84(param_1 + 0x120,4);
  }
  *(u8 *)(param_1 + 0x12d) = 1;
  FUN_00111474(param_1,0);
}
