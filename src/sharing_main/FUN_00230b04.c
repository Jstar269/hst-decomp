/* HSTMATCH module=hstp_trans_main.prx start=0x00230b04 end=0x00230b2c symbol=FUN_00230b04 lang=c99 */
/* Clone of src/eboot/FUN_00221590.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00108aec();

void FUN_00230b04(int param_1)
{
  if (*(u8 *)(param_1 + 0x58) == '\0') {
    FUN_00108aec();
  }
}
