/* HSTMATCH module=hstp_trans_main.prx start=0x00228ee0 end=0x00228f68 symbol=FUN_00228ee0 lang=c99 */
/* Clone of src/eboot/FUN_002199c8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00051e30();
extern void FUN_000522c0();
extern void FUN_0005b540();

void FUN_00228ee0(u32 *param_1)
{
  int iVar2;
  int iVar1;
  
  FUN_00051e30(*param_1,0,0,0x1e0,0x110,0,0);
  iVar2 = 0;
  iVar1 = 0;
  do {
    FUN_0005b540(param_1[1] + iVar1,*param_1,0,0);
    iVar2 = iVar2 + 1;
    iVar1 = iVar1 + 0xa0;
  } while (iVar2 < 200);
  FUN_000522c0(*param_1);
}
