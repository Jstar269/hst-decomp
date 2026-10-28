/* HSTMATCH module=hstp_trans_main.prx start=0x002bd088 end=0x002bd0f4 symbol=FUN_002bd088 lang=c99 */
/* Clone of src/eboot/global_mode_route_002ad8cc.c (hstclone.py tag u6cr1s): addresses substituted; exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: expressed the three accepted values in retail test order with a switch; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003f39a8;
extern int FUN_00177d4c();
extern void FUN_002bcf14();

void FUN_002bd088(void)
{
  u32 uVar1;
  int uVar2;
  
  uVar2 = 0;
  switch (DAT_003f39a8) {
  case 0x14:
  case 0x47:
  case 0x48:
    uVar2 = 1;
    break;
  default:
    break;
  }
  uVar1 = FUN_00177d4c();
  FUN_002bcf14(uVar2,uVar1,0);
}
