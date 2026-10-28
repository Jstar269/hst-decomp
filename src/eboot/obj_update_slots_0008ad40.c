/* HSTMATCH module=EBOOT.BIN start=0x0008ad40 end=0x0008add8 symbol=FUN_0008ad40 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a3/v10) corrected by hand: the byte flag at +0x4c is unsigned char (lbu) and the loop counter is declared before the pointer for the s-register assignment; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003386b8;
extern u32 DAT_00338af0;
extern void FUN_0009619c();

void FUN_0008ad40(char *param_1)
{
  u32 uVar2;
  char *iVar1;
  
  if ((DAT_003386b8 != '\0') && (DAT_00338af0 != 0)) {
    uVar2 = 0;
    iVar1 = param_1;
    do {
      if (*(int *)(iVar1 + 0x70) != 0) {
        FUN_0009619c(*(int *)(iVar1 + 0x70),*(int *)(param_1 + 0x5c),*(u32 *)(param_1 + 100))
        ;
      }
      uVar2 = uVar2 + 1;
      iVar1 = iVar1 + 4;
    } while (uVar2 < 4);
    if (*(unsigned char *)(param_1 + 0x4c) == 0) {
      *(u8 *)(param_1 + 0x4c) = 1;
      *(u32 *)(param_1 + 0x50) = 0x708;
    }
  }
}
