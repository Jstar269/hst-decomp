/* HSTMATCH module=hstp_trans_main.prx start=0x00291520 end=0x00291588 symbol=FUN_00291520 lang=c99 */
/* Clone of src/eboot/FUN_002800ac_002800ac.c (hstclone.py tag u5cr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1/v0c) corrected by hand: reused and stored the allocation result on both null and initialized paths; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003a7728;
extern u32 DAT_003f3b20;
extern char DAT_003a76e8[];
extern int FUN_00000bcc();
extern int * FUN_00065884();
extern u32 FUN_00065ab8();

u32 * FUN_00291520(u32 *param_1)
{
  int iVar1;
  u32 uVar2;
  
  *param_1 = 0;
  DAT_003f3b20 = (unsigned int)(param_1);
  iVar1 = FUN_00000bcc(0x10);
  if (iVar1 != 0) {
    iVar1 = (int)FUN_00065884(iVar1);
  }
  *param_1 = iVar1;
  FUN_00065ab8(iVar1,DAT_003a76e8 + 0x10,1,&DAT_003a7728);
  return param_1;
}

