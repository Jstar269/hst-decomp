/* HSTMATCH module=EBOOT.BIN start=0x00051050 end=0x000510c0 symbol=FUN_00051050 lang=c99 */
/* Clone of src/sharing_main/FUN_00051964.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00306fc8;
extern void FUN_00051118();
extern void FUN_00051274();

u32 * FUN_00051050(u32 *param_1,u32 param_2,u32 param_3,u32 param_4)
{
  *param_1 = (unsigned int)(&DAT_00306fc8);
  FUN_00051118();
  FUN_00051274(param_1,param_2,param_3,param_4,0x10);
  return param_1;
}
