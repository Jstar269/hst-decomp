/* HSTMATCH module=EBOOT.BIN start=0x000c482c end=0x000c48d4 symbol=FUN_000c482c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"
extern u32 DAT_00338ac4;
extern u32 DAT_00338b44;
extern u32 FUN_000ba78c(u32);
extern int FUN_000def58();

u32 FUN_000c482c(int param_1,int param_2)
{
  int iVar1;

  switch (param_2) {
  case 0x13:
    if (DAT_00338ac4 != 0) {
      FUN_000ba78c(DAT_00338ac4);
    }
    break;
  case 0x14:
    iVar1 = FUN_000def58(DAT_00338b44);
    if (iVar1 != 0) {
      *(u8 *)(*(int *)(param_1 + 0x784) + 4) = 1;
    }
    break;
  case 0x19:
    iVar1 = FUN_000def58(DAT_00338b44);
    if (iVar1 != 0) {
      *(u8 *)(*(int *)(param_1 + 0x784) + 4) = 1;
    }
    break;
  }
  return 0;
}
