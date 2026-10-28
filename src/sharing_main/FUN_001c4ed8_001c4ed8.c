/* HSTMATCH module=hstp_trans_main.prx start=0x001c4ed8 end=0x001c4f58 symbol=FUN_001c4ed8 lang=c99 */
/* Clone of src/eboot/FUN_001b7218_001b7218.c (hstclone.py tag u1r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1/v0) corrected by hand: symbol-address and pointer/float helper prototypes; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001c04c4(int *param_1);
extern void FUN_001c2130(int *param_1, float param_2);
extern void FUN_001c2384(int *param_1, float param_2);
extern void FUN_001c2670(int *param_1, float param_2);
extern void FUN_001c6408();
extern int DAT_003eaad8;

void FUN_001c4ed8(int param_1)
{
  FUN_001c6408();
  *(u8 *)(param_1 + 0x78) = 1;
  FUN_001c2130(&DAT_003eaad8,0.1f);
  FUN_001c2384(&DAT_003eaad8,0.1f);
  FUN_001c2670(&DAT_003eaad8,0.1f);
  FUN_001c04c4(&DAT_003eaad8);
}
