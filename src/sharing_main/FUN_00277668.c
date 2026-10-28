/* HSTMATCH module=hstp_trans_main.prx start=0x00277668 end=0x002776c0 symbol=FUN_00277668 lang=c99 */
/* Clone of src/eboot/FUN_00266760.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 FUN_001377d0();
extern u32 FUN_00137a18();
extern void FUN_00277704();

void FUN_00277668(int param_1)
{
  u8 cVar1;
  u8 uVar2;
  
  cVar1 = FUN_001377d0(param_1 + 0x80);
  if (cVar1 != '\0') {
    uVar2 = FUN_00137a18(param_1 + 0x80);
    *(u8 *)(param_1 + 0x120) = uVar2;
    if (*(u8 *)(param_1 + 0x120) == '\0') {
      FUN_00277704(param_1,1);
    }
  }
}
