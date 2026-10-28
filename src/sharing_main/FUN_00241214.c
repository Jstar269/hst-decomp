/* HSTMATCH module=hstp_trans_main.prx start=0x00241214 end=0x00241268 symbol=FUN_00241214 lang=c99 */
/* Clone of src/eboot/FUN_00231114.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003f398c;
extern void FUN_00000a00();
extern void FUN_002412cc();

int FUN_00241214(int param_1,short param_2)
{
  if (param_1 != 0) {
    DAT_003f398c = 0;
    FUN_002412cc();
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
