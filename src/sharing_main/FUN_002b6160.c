/* HSTMATCH module=hstp_trans_main.prx start=0x002b6160 end=0x002b61d0 symbol=FUN_002b6160 lang=c99 */
/* Clone of src/eboot/FUN_002a69d0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003a9b90;
extern u32 DAT_003f46a0;
extern void FUN_00111aa4();
extern void FUN_0011988c();
extern u8 * FUN_0020d1e0();

void FUN_002b6160(int param_1,int param_2)
{
  u32 uVar1;
  
  FUN_00111aa4(*(u32 *)(param_1 + 0x178),param_2,0);
  if (DAT_003f46a0 != 0) {
    uVar1 = (unsigned int)(FUN_0020d1e0(0x12,0x31,*(u32 *)(&DAT_003a9b90 + param_2 * 4)));
    FUN_0011988c(DAT_003f46a0,uVar1,0);
  }
}
