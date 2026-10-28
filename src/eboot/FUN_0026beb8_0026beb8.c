/* HSTMATCH module=EBOOT.BIN start=0x0026beb8 end=0x0026bf18 symbol=FUN_0026beb8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: restored the second initialization-helper argument; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_002cfc8c;
extern void FUN_0001dfe8();
extern void FUN_0001e23c();
extern void FUN_0026bf18(u32 *param_1, int param_2);
extern void FUN_00281128();

void FUN_0026beb8(u32 *param_1)
{
  FUN_0001dfe8(DAT_002cfc8c,0x2000);
  FUN_0001e23c(DAT_002cfc8c,0x2000,1);
  *(u8 *)(param_1 + 0x2ef) = 1;
  *(u8 *)(param_1 + 0x2f1) = 0;
  FUN_0026bf18(param_1,1);
  FUN_00281128(*param_1);
}
