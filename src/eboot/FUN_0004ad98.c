/* HSTMATCH module=EBOOT.BIN start=0x0004ad98 end=0x0004ae08 symbol=FUN_0004ad98 lang=c99 */
/* Clone of src/sharing_main/FUN_0004af74.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0004ae58();
extern u32 FUN_0004ae68();

u32 FUN_0004ad98(u32 param_1,u32 param_2,u32 param_3,u32 param_4, u32 param_5)
{
  FUN_0004ae58(param_1);
  FUN_0004ae68(param_1,param_2,param_3,param_4,param_5);
  return param_1;
}
