/* HSTMATCH module=hstp_trans_main.prx start=0x0026f428 end=0x0026f4c0 symbol=FUN_0026f428 lang=c99 */
/* Clone of src/eboot/FUN_0025e600.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b264c;
extern u8 DAT_003b2cb8;
extern u32 DAT_003f3af4;
extern void FUN_00000788();
extern void FUN_00000a00();
extern u32 * FUN_001087a8();
extern void FUN_0026f328();

u32 * FUN_0026f428(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b2cb8);
    DAT_003f3af4 = 0;
    if (param_1 + 0xbc != (u32 *)0x0) {
      FUN_00000788(param_1 + 0xbc,FUN_0026f328,0xf0,3);
    }
    if (param_1 != (u32 *)0x0) {
      *param_1 = (unsigned int)(&DAT_003b264c);
      FUN_001087a8(param_1,0);
    }
    if (param_2 > 0) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
