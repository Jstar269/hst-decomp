/* HSTMATCH module=hstp_trans_main.prx start=0x000d45a4 end=0x000d4698 symbol=FUN_000d45a4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v0) corrected by hand: rebuilt the mode ladder as a switch and typed the float cleanup argument; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_00059ca4(void *, int);
extern void FUN_0005ff00(void *, float);

u32 FUN_000d45a4(int param_1,int param_2)
{
  unsigned char cVar1;
  int iVar2;
  
  switch (param_2) {
  case 0:
  case 1:
    break;
  case 0x16:
  case 0xe:
  case 8:
  case 0xc:
  case 9:
  case 10:
    iVar2 = *(int *)(param_1 + 0x3c);
    if (iVar2 != 0) {
      FUN_00059ca4((void *)iVar2,-1);
      FUN_0005ff00((void *)iVar2,0.0f);
      *(u32 *)(iVar2 + 0xd0) = 0;
      *(u32 *)(param_1 + 0x3c) = 0;
    }
    cVar1 = *(unsigned char *)(param_1 + 0xb0);
    if (cVar1 != 0) {
      iVar2 = *(int *)(param_1 + 0x9c);
      FUN_00059ca4((void *)iVar2,-1);
      FUN_0005ff00((void *)iVar2,0.0f);
      *(u32 *)(iVar2 + 0xd0) = 0;
      *(u8 *)(param_1 + 0xb0) = 0;
    }
    break;
  case 0xb:
    break;
  default:
    break;
  }
  return 0;
}
