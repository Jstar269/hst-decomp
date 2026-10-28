/* HSTMATCH module=hstp_trans_main.prx start=0x001c64d4 end=0x001c657c symbol=FUN_001c64d4 lang=c99 */
/* Clone of src/eboot/flag_update_001b87e8.c (hstclone.py tag u2r1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: express the two guarded paths and shared flag store explicitly; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003eaad8;
extern void FUN_001c2384(int *,float);
extern int FUN_001c2514(int *,int);

void FUN_001c64d4(int param_1,int param_2,int param_3)
{
  int flag;

  if (param_2 == 0) goto zero_case;
  if (*(u8 *)(param_1 + 0x78) == 0) goto zero_case;
  FUN_001c2514((int *)&DAT_003eaad8,param_2);
  goto store_flag;

zero_case:
  if (param_2 != 0) goto store_flag;
  if (*(u8 *)(param_1 + 0x78) != 0) goto store_flag;
  FUN_001c2514((int *)&DAT_003eaad8,param_2);
  if (param_3 == 0) goto store_flag;
  FUN_001c2384((int *)&DAT_003eaad8,0.5f);

store_flag:
  flag = param_2 != 0;
  flag ^= 1;
  *(u8 *)(param_1 + 0x78) = (u8)flag;
}
