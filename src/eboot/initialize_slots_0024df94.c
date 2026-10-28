/* HSTMATCH module=EBOOT.BIN start=0x0024df94 end=0x0024e064 symbol=FUN_0024df94 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: reordered nested-loop counters and isolated the final record cursor; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0024e1f8();

int FUN_0024df94(int param_1)
{
  int iVar1;
  int iVar3;
  int iVar2;
  
  iVar1 = 0;
  do {
    iVar3 = 0;
    do {
      iVar2 = 0;
      do {
        FUN_0024e1f8(param_1,iVar1 == 0,iVar3,iVar2,0xffffffff);
        iVar2 = iVar2 + 1;
      } while (iVar2 < 6);
      iVar3 = iVar3 + 1;
    } while (iVar3 < 0x10);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 2);
  *(u32 *)(param_1 + 0xc0) = 0;
  *(u32 *)(param_1 + 0xc4) = 0;
  {
    int off = 0;
    char *p = (char *)param_1;
    do {
      *(u32 *)(p + 200) = 0;
      *(u32 *)(p + 0xcc) = 0;
      *(u32 *)(p + 0xd0) = 0;
      *(u32 *)(p + 0xd4) = 0;
      *(u32 *)(p + 0xd8) = 0;
      *(u32 *)(p + 0xdc) = 0;
      off = off + 7;
      *(u32 *)(p + 0xe0) = 0;
      p = p + 0x1c;
    } while (off < 0xe);
  }
  return param_1;
}
