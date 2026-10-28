/* HSTMATCH module=hstp_trans_main.prx start=0x001c0da0 end=0x001c0e00 symbol=FUN_001c0da0 lang=c99 */
/* Clone of src/eboot/FUN_001b2c70.c (hstclone.py tag c43): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_00063304();

void FUN_001c0da0(u32 *param_1)
{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)*param_1;
  iVar1 = piVar2[0xb2];
  if (iVar1 == 0) {
    iVar1 = *piVar2;
  }
  else {
    if (iVar1 != 0) {
      FUN_00063304(iVar1,1);
      piVar2[0xb2] = 0;
    }
  }
  if (((*piVar2) != 0) && ((*piVar2) != 0)) {
    FUN_00063304((*piVar2),1);
    *piVar2 = 0;
  }
}
