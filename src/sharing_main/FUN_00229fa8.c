/* HSTMATCH module=hstp_trans_main.prx start=0x00229fa8 end=0x00229fe0 symbol=FUN_00229fa8 lang=c99 */
/* Clone of src/eboot/FUN_0021aa34.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0022a030();
extern void FUN_0022a154();

u32 * FUN_00229fa8(u32 *param_1)
{
  *param_1 = 0;
  FUN_0022a030();
  FUN_0022a154(param_1,0xb);
  return param_1;
}
