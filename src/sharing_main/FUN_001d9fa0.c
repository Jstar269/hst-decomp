/* HSTMATCH module=hstp_trans_main.prx start=0x001d9fa0 end=0x001da030 symbol=FUN_001d9fa0 lang=c99 */
/* Clone of src/eboot/FUN_001cb7d0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_003ea8ec;
extern void FUN_00111aa4();
extern void FUN_0011e940();
extern void FUN_001d06dc();
extern void FUN_001dbf68();
extern u8 * FUN_00238a68();

void FUN_001d9fa0(int param_1,u32 param_2)
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x15c);
  *(u8 *)(iVar2 + 0xb0) = 0;
  iVar1 = (int)(FUN_00238a68(iVar2 + 0x34,*(u32 *)(iVar2 + 0x24),param_2,0));
  if (iVar1 != 0) {
    FUN_0011e940(DAT_003ea8ec,1,iVar1,0,0);
    FUN_00111aa4(**(u32 **)(DAT_003ea8ec + 0x58),0,0);
    FUN_001dbf68(iVar2,4,1);
    FUN_001d06dc(iVar2);
  }
}
