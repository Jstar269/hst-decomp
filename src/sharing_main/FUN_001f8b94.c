/* HSTMATCH module=hstp_trans_main.prx start=0x001f8b94 end=0x001f8bd4 symbol=FUN_001f8b94 lang=c99 */
/* Clone of src/eboot/FUN_001ea8f0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

void FUN_001f8b94(int *param_1)
{
  int iVar1;
  int iVar3;
  int iVar2;
  
  iVar1 = *param_1;
  iVar3 = 0;
  iVar2 = iVar1;
  do {
    *(u32 *)(iVar2 + 1000) = 0xffffffff;
    *(u32 *)(iVar2 + 0x3ec) = 0xffffffff;
    *(u32 *)(iVar2 + 0x3f0) = 0xffffffff;
    *(u32 *)(iVar2 + 0x3f4) = 0xffffffff;
    *(u32 *)(iVar2 + 0x3f8) = 0xffffffff;
    iVar3 = iVar3 + 1;
    *(u32 *)(iVar2 + 0x3fc) = 0xffffffff;
    iVar2 = iVar2 + 0x18;
  } while (iVar3 < 2);
  *(u8 *)(iVar1 + 0x418) = 0;
}
