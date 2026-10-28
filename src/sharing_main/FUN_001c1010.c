/* HSTMATCH module=hstp_trans_main.prx start=0x001c1010 end=0x001c1090 symbol=FUN_001c1010 lang=c99 */
/* Clone of src/eboot/FUN_001b2ee0.c (hstclone.py tag u3r3s): addresses substituted; exact match verified; names and types await human review. */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. matching idiom: three if (p != 0) { if (p != 0) { free(p,1); p-field = 0; } } blocks reproduce retail's duplicated null guard and beqzl+beqz chain. */
#include "hst/types.h"

extern int FUN_00063304();

void FUN_001c1010(int *param_1)
{
  int iVar1;
  int iVar2;

  iVar2 = *param_1;
  iVar1 = *(int *)(iVar2 + 0xfc);
  if (iVar1 != 0) {
    if (iVar1 != 0) {
      FUN_00063304(iVar1,1);
      *(u32 *)(iVar2 + 0xfc) = 0;
    }
  }
  iVar1 = *(int *)(iVar2 + 0xf8);
  if (iVar1 != 0) {
    if (iVar1 != 0) {
      FUN_00063304(iVar1,1);
      *(u32 *)(iVar2 + 0xf8) = 0;
    }
  }
  iVar1 = *(int *)(iVar2 + 0x2b0);
  if (iVar1 != 0) {
    if (iVar1 != 0) {
      FUN_00063304(iVar1,1);
      *(u32 *)(iVar2 + 0x2b0) = 0;
    }
  }
}
