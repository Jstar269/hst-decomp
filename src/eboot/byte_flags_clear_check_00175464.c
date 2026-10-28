/* HSTMATCH module=EBOOT.BIN start=0x00175464 end=0x0017551c symbol=FUN_00175464 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: the three byte tests written as one || chain (if (b8 != 0 || b11 != 0 || b12 != 0) bVar1 = false; else bVar1 = true;) instead of Ghidra's nested if/else; exact match verified; names and types await human review. */
#include "hst/types.h"
typedef int (*Fn)();

u32 FUN_00175464(int param_1)
{
  bool bVar1;
  int iVar2;
  
  iVar2 = ((Fn)*(int *)(param_1 + 0x558))();
  if ((iVar2 != 0x7fff) && (iVar2 = ((Fn)*(int *)(param_1 + 0x558))(), iVar2 != 0x7ffe)) {
    iVar2 = *(int *)(param_1 + 0x538);
    iVar2 = *(int *)(*(int *)(*(int *)(iVar2 + 0x18) + *(int *)(iVar2 + 8) * 0xc) +
                    *(int *)(iVar2 + 4) * 4);
    if (*(u8 *)(iVar2 + 8) != 0 || *(u8 *)(iVar2 + 0xb) != 0 || *(u8 *)(iVar2 + 0xc) != 0) bVar1 = false; else bVar1 = true;
    if (bVar1) return 1;
  }
  return 0;
}
