/* HSTMATCH module=hstp_trans_main.prx start=0x0026f328 end=0x0026f390 symbol=FUN_0026f328 lang=c99 */
/* Clone of src/eboot/FUN_0025e500_0025e500.c (hstclone.py tag u4r4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: modeled the resource pointer at +0x20 as a direct field store; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0a68;
extern void FUN_00000a00();
extern u32 * FUN_0010642c();

struct ResourceSlot { char padding[0x20]; u8 *resource; };

int FUN_0026f328(int param_1,short param_2)
{
  if (param_1 != 0) {
    if (param_1 + 0x20 != 0) {
      ((struct ResourceSlot *)param_1)->resource = &DAT_003b0a68;
      FUN_0010642c(param_1 + 0x20,0);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
