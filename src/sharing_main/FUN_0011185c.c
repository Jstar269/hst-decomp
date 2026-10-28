/* HSTMATCH module=hstp_trans_main.prx start=0x0011185c end=0x001118ac symbol=FUN_0011185c lang=c99 */
/* Clone of src/eboot/FUN_0010b684.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00110f78();
extern void FUN_00111474();

void FUN_0011185c(int param_1,u32 param_2,u8 param_3)
{
  FUN_00111474(param_1,0);
  *(u8 *)(param_1 + 0x114) = param_3;
  *(u32 *)(param_1 + 0x118) = param_2;
  FUN_00110f78(param_1);
}
