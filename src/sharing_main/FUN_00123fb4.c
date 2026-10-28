/* HSTMATCH module=hstp_trans_main.prx start=0x00123fb4 end=0x00123ff4 symbol=FUN_00123fb4 lang=c99 */
/* Clone of src/eboot/FUN_00118b4c.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int * FUN_00123ff4();
extern u32 FUN_00124128();

u32 FUN_00123fb4(u32 param_1,u32 param_2,u32 param_3)
{
  FUN_00124128(param_1);
  FUN_00123ff4(param_1,param_3);
  return param_1;
}
