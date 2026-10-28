/* HSTMATCH module=EBOOT.BIN start=0x00162200 end=0x001622d8 symbol=FUN_00162200 lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag t0), refined by hstperm.py random mutation from try/gen-s256b/v0/FUN_00162200.c; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_00341508;
extern u32 DAT_0034150c;
extern u32 DAT_00341510;
extern void FUN_000006e8();
extern void FUN_00000a00();
extern int * FUN_00165724();
extern int * FUN_00165840();
extern void FUN_001622d8();

int FUN_00162200(int param_1,short param_2)
{
  int iVar1;
  
  if (param_1 != 0) {
    if (param_1 == DAT_00341508) {
      if (DAT_0034150c != 0) {
        FUN_000006e8(DAT_0034150c,FUN_00162200);
        DAT_0034150c = 0;
      }
      if (DAT_00341510 != 0) {
        FUN_000006e8(DAT_00341510,FUN_001622d8);
        DAT_00341510 = 0;
      }
    }
    iVar1 = param_1 + 0xc;
    if ((iVar1 != 0) && (iVar1 != 0)) {
      FUN_00165840(iVar1,0);
    }
    if ((param_1 != 0) && (0 != param_1)) {
      FUN_00165724(param_1,0);
    }
    if (0 < param_2) {
      FUN_00000a00(param_1);
    }
  }
  return param_1;
}
