/* HSTMATCH module=hstp_trans_main.prx start=0x0027ce90 end=0x0027cef0 symbol=FUN_0027ce90 lang=c99 */
/* Clone of src/eboot/FUN_0026beb8_0026beb8.c (hstclone.py tag u4r4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: restored the second initialization-helper argument; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003751d4;
extern void FUN_0001dc34();
extern void FUN_0001de88();
extern void FUN_0027cef0(u32 *param_1, int param_2);
extern void FUN_002924a0();

void FUN_0027ce90(u32 *param_1)
{
  FUN_0001dc34(DAT_003751d4,0x2000);
  FUN_0001de88(DAT_003751d4,0x2000,1);
  *(u8 *)(param_1 + 0x2ef) = 1;
  *(u8 *)(param_1 + 0x2f1) = 0;
  FUN_0027cef0(param_1,1);
  FUN_002924a0(*param_1);
}
