/* HSTMATCH module=EBOOT.BIN start=0x0010b29c end=0x0010b308 symbol=FUN_0010b29c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_0010b29c(int param_1)
{
  int i;

  i = *(int *)(param_1 + 0xd4);
  switch (*(int *)(param_1 + 0x118)) {
  case 1:
    return *(u32 *)(*(int *)(param_1 + 0x10) + i * 4);
  case 2:
    return *(u32 *)(*(int *)(param_1 + 0x10) + (i + 2) * 4);
  case 0:
  default:
    return *(u32 *)(*(int *)(param_1 + 0x10) + (i + 1) * 4);
  }
}
