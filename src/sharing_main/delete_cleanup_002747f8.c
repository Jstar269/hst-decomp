/* HSTMATCH module=hstp_trans_main.prx start=0x002747f8 end=0x002748bc symbol=FUN_002747f8 lang=c99 */
/* Clone of src/eboot/delete_cleanup_0026397c.c (hstclone.py tag u6cr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2/v0c) corrected by hand: typed the float argument and deallocation receiver; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b2d94;
extern u32 DAT_003daec4;
extern u32 DAT_003ea8ec;
extern void FUN_00000a00(u32 *);
extern void FUN_0006433c(float,u32);
extern void FUN_00108f54(u32, int);
extern u32 * FUN_00268630();
extern u32 * FUN_0026f428();

u32 * FUN_002747f8(u32 *param_1,short param_2)
{
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b2d94);
    FUN_0006433c(203000.0f,DAT_003daec4);
    FUN_00108f54(DAT_003ea8ec,1);
    *(u8 *)(param_1[400] + 0x616) = 0;
    *(u8 *)(param_1[400] + 0x736) = 0;
    *(u8 *)(param_1[400] + 0x856) = 0;
    *(u8 *)(param_1[400] + 0x617) = 0;
    *(u8 *)(param_1[400] + 0x737) = 0;
    *(u8 *)(param_1[400] + 0x857) = 0;
    FUN_0026f428(param_1 + 0x618,-1);
    FUN_00268630(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
