/* HSTMATCH module=hstp_trans_main.prx start=0x0026b500 end=0x0026b540 symbol=FUN_0026b500 lang=c99 */
/* Clone of src/eboot/FUN_00118b4c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int * FUN_0026b540();
extern u32 FUN_0026b674();

u32 FUN_0026b500(u32 param_1,u32 param_2,u32 param_3)
{
  FUN_0026b674(param_1);
  FUN_0026b540(param_1,param_3);
  return param_1;
}
