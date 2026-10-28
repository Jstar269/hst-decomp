/* HSTMATCH module=hstp_trans_main.prx start=0x002031cc end=0x0020321c symbol=FUN_002031cc lang=c99 */
/* Clone of src/eboot/FUN_001f4c04.c (hstclone.py tag u6cr4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag p128a) corrected by hand: split the byte guard so the dependent object load fills its delay slot before the global-pointer check; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003e1a54;
extern void FUN_0005d42c(int param_1, int param_2, float *param_3);

void FUN_002031cc(int param_1)
{
  int child;
  int value;
  u32 global;

  if (*(u8 *)(param_1 + 0x514) == 0) return;
  child = *(int *)(param_1 + 0x584);
  global = DAT_003e1a54;
  if (global == 0) return;
  value = *(int *)(child + 0x94);
  if (value != 1) return;
  FUN_0005d42c(global, 0, (float *)(child + 0x110));
}
