/* HSTMATCH module=hstp_trans_main.prx start=0x00131e9c end=0x00131f8c symbol=FUN_00131e9c lang=c99 data=0x00381854 */
/* Clone of src/eboot/FUN_00126c2c.c (hstclone.py tag c30): addresses substituted; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x00381854-0x00381870) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
/* Ghidra pseudocode (hstgen.py tag q2) corrected by hand: the member sub-object null test restored (Ghidra folded its offset into the compared constant); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b131c;
extern u8 DAT_003b1330;
extern void FUN_00000a00();
extern u32 * FUN_00093544();
extern int FUN_000dbb20();
extern int * FUN_000ed9b8();
extern void FUN_00131f8c();
extern u32 * FUN_00297f98();

u32 * FUN_00131e9c(u32 *param_1,short param_2)
{
  u32 *puVar1;
  
  if (param_1 != (u32 *)0x0) {
    *param_1 = (unsigned int)(&DAT_003b131c);
    param_1[0x38] = (unsigned int)(&DAT_003b1330);
    FUN_00131f8c("Avatar: destructor called.\n");
    puVar1 = param_1 + 0x105;
    if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
      FUN_000ed9b8(puVar1,0);
    }
    puVar1 = param_1 + 0xdc;
    if (puVar1 != (u32 *)0x0) {
      puVar1 = param_1 + 0xfd;
      if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
        FUN_000ed9b8(puVar1,0);
      }
      puVar1 = param_1 + 0xf8;
      if ((puVar1 != (u32 *)0x0) && (puVar1 != (u32 *)0x0)) {
        FUN_000ed9b8(puVar1,0);
      }
    }
    FUN_000dbb20(param_1 + 0x96,0xffffffff);
    FUN_00297f98(param_1 + 0x38,0);
    FUN_00093544(param_1,0);
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
