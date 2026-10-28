/* HSTMATCH module=hstp_trans_main.prx start=0x0021fecc end=0x0021ff70 symbol=FUN_0021fecc lang=c99 */
/* Clone of src/eboot/FUN_002111cc_002111cc.c (hstclone.py tag u4r4s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: compared the parameter from the variable side and retained the scaled random factor with a compound multiply; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_0001342c();

float FUN_0021fecc(float param_1,float param_2)
{
  u32 uVar1;
  float randValue;
  float scaled;
  float fVar2;
  
  if (param_1 > 0.0f) {
    uVar1 = FUN_0001342c();
    randValue = (float)(int)(uVar1 & 0xfffff800);
    scaled = (param_1 + param_2) * 4.656613e-10f;
    scaled *= randValue;
    fVar2 = -param_2 + scaled;
  }
  else {
    uVar1 = FUN_0001342c();
    randValue = (float)(int)(uVar1 & 0xfffff800);
    scaled = (param_2 - param_1) * 4.656613e-10f;
    scaled *= randValue;
    fVar2 = param_1 + scaled;
  }
  return fVar2;
}
