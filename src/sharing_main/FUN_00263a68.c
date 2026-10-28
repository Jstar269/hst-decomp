/* HSTMATCH module=hstp_trans_main.prx start=0x00263a68 end=0x00263b28 symbol=FUN_00263a68 lang=c99 */
/* Clone of src/eboot/FUN_00253630.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003a57dc;
extern char DAT_003a57b8[];
extern int * FUN_00065884();
extern int * FUN_000658cc();
extern u32 FUN_00065ab8();
extern u32 FUN_00065fa4();
extern int FUN_00066038();

u32 * FUN_00263a68(u32 *param_1)
{
  int iVar1;
  int iVar2;
  u8 auStack_10 [16];
  
  *param_1 = 0;
  FUN_00065884(auStack_10);
  FUN_00065ab8(auStack_10,DAT_003a57b8,0,&DAT_003a57dc);
  param_1[6] = 0;
  iVar2 = 0;
  iVar1 = FUN_00065fa4(auStack_10);
  if (0 < iVar1) {
    do {
      iVar1 = FUN_00066038(auStack_10,iVar2,3);
      if (iVar1 != 0) {
        iVar1 = param_1[6];
        param_1[6] = iVar1 + 1;
        param_1[iVar1 + 7] = iVar2;
      }
      iVar2 = 1 + iVar2;
      iVar1 = FUN_00065fa4(auStack_10);
    } while (iVar2 < iVar1);
  }
  FUN_000658cc(auStack_10,0xffffffff);
  return param_1;
}
