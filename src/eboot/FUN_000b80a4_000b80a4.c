/* HSTMATCH module=EBOOT.BIN start=0x000b80a4 end=0x000b8118 symbol=FUN_000b80a4 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_000b8118(void);

u32 FUN_000b80a4(int param_1, int param_2)
{
  switch (param_2) {
  case 8:
  case 0xe:
    if (param_2 == 8)
      *(u32 *)(param_1 + 100) = *(u32 *)(param_1 + 0x68);
    else
      *(u32 *)(param_1 + 100) = *(u32 *)(param_1 + 0x6c);
    FUN_000b8118();
    break;
  case 0x14:
    *(u8 *)(param_1 + 0x3d) = 1;
    break;
  default:
    break;
  }
  return 0;
}
