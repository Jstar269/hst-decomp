/* HSTMATCH module=hstp_trans_main.prx start=0x001a6b24 end=0x001a6b98 symbol=FUN_001a6b24 lang=c99 */
/* Clone of src/eboot/gcall_clamp_0019a19c.c (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag gen-a2/v0) corrected by hand: u8 field at +0xea read as unsigned char (lbu) instead of char; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003eaad8;
extern float FUN_000f3560(float param_1,float param_2,float param_3,float param_4);
extern void FUN_00108a2c();
extern void FUN_001a6900();
extern int FUN_001bfc3c();

void FUN_001a6b24(int param_1)
{
  float fVar1;
  
  if (*(u8 *)(*(int *)(param_1 + 0x54) + 0xea) != 0) {
    FUN_001bfc3c((int *)&DAT_003eaad8,1);
  }
  fVar1 = FUN_000f3560(*(float *)(param_1 + 0x5c),1.0f,0.5f,0.005f);
  *(float *)(param_1 + 0x5c) = fVar1;
  FUN_001a6900(param_1);
  FUN_00108a2c(param_1);
}
