/* HSTMATCH module=hstp_trans_main.prx start=0x00063dac end=0x00063e2c symbol=FUN_00063dac lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003daec0;
extern void FUN_00062fd4(float);
extern void FUN_002c7818();

int FUN_00063dac(int param_1)
{
  int r;
  int i;

  r = 0;
  for (i = 0; i < param_1; i++) {
    if (DAT_003daec0 == 0) {
      r = 1;
      break;
    }
    FUN_00062fd4(30.0f);
    FUN_002c7818();
    FUN_002c7818();
  }
  return r;
}
