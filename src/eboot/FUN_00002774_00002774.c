/* HSTMATCH module=EBOOT.BIN start=0x00002774 end=0x000027d4 symbol=FUN_00002774 lang=c99 */
/* Clone of src/sharing_main/FUN_00002774.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0030a040;
extern u8 DAT_0030a044;

int FUN_00002774(u32 param_1,int param_2)
{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = (int *)&DAT_0030a040;
  do {
    if (*piVar2 == 0) {
      *(u32 *)(&DAT_0030a040 + iVar1 * 8) = param_1;
      piVar2 = (int *)((int)&DAT_0030a044 + iVar1 * 8);
      *piVar2 = param_2;
      *piVar2 = param_2 + -0xc;
      return iVar1;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 2;
  } while (iVar1 < 0x10);
  return -1;
}
