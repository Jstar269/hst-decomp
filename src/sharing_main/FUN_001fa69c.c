/* HSTMATCH module=hstp_trans_main.prx start=0x001fa69c end=0x001fa6f8 symbol=FUN_001fa69c lang=c99 */
/* Clone of src/eboot/FUN_001ec35c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003f3470;
extern void FUN_00000a00();
extern void FUN_001fa758();
extern void FUN_001fadcc();

int FUN_001fa69c(int param_1,short param_2)
{
  if (param_1 != 0) {
    DAT_003f3470 = 0;
    FUN_001fa758();
    FUN_001fadcc(param_1);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
