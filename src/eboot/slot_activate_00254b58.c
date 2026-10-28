/* HSTMATCH module=EBOOT.BIN start=0x00254b58 end=0x00254bd0 symbol=FUN_00254b58 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: replaced numeric address 0x34179c with &DAT_0034179c; exact match verified; names and types await human review. */

#include "hst/types.h"

extern char DAT_0034179c;
extern u8 DAT_0034b340;
extern void FUN_00194e3c();
extern u32 FUN_001b1c44();
extern void FUN_00253f38();

void FUN_00254b58(int param_1,int param_2)
{
  if (*(int *)(&DAT_0034b340 + param_2 * 4) != 0) {
    FUN_00194e3c(*(int *)(&DAT_0034b340 + param_2 * 4),param_2,0,1);
    FUN_00253f38(param_2);
    *(u8 *)(param_2 + param_1 + 4) = 1;
    FUN_001b1c44(&DAT_0034179c,0x16);
  }
}
