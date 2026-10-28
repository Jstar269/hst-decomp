/* HSTMATCH module=EBOOT.BIN start=0x00002f90 end=0x00002fc0 symbol=FUN_00002f90 lang=c99 */
/* Clone of src/sharing_main/FUN_00002f90.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00002fc0();
extern u32 FUN_0000300c();

u32 FUN_00002f90(u32 param_1)
{
  FUN_0000300c();
  FUN_00002fc0(param_1);
  return param_1;
}
