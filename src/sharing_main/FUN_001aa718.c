/* HSTMATCH module=hstp_trans_main.prx start=0x001aa718 end=0x001aa7b4 symbol=FUN_001aa718 lang=c99 */
/* Clone of src/eboot/FUN_0019d270.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0a68;
extern u8 DAT_003b122c;
extern u8 DAT_003b24b4;
extern void FUN_00000a00();
extern u32 * FUN_0010642c();
extern int * FUN_0010d2d4();

u32 * FUN_001aa718(u32 *param_1,short param_2)
{
  u32 *puVar1;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b24b4);
    if (param_1 != (u32 *)0x0) {
      puVar1 = param_1 + 0x48;
      *param_1 = (unsigned int)(&DAT_003b122c);
      if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
        FUN_0010d2d4(puVar1,0);
      }
      if (param_1 != (u32 *)0x0) {
        *param_1 = (unsigned int)(&DAT_003b0a68);
        FUN_0010642c(param_1,0);
      }
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
