/* HSTMATCH module=EBOOT.BIN start=0x0005eb98 end=0x0005ec14 symbol=FUN_0005eb98 lang=c99 */
/* Clone of src/sharing_main/FUN_0005f988.c (hstclone.py tag c20r): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_0005f230();
extern void FUN_0005f58c();

void FUN_0005eb98(int param_1)
{
  *(u32 *)(param_1 + 0xa0) = 0xffffffff;
  *(u32 *)(param_1 + 0xa4) = 0;
  *(u8 *)(param_1 + 0xc0) = 0;
  *(u32 *)(param_1 + 0xc4) = 0x3f800000;
  *(u32 *)(param_1 + 200) = 0;
  *(u32 *)(param_1 + 0xcc) = 0;
  *(u32 *)(param_1 + 0xd0) = 0;
  if (*(u32 *)(param_1 + 0xb0) < 0x40) {
    FUN_0005f58c(param_1 + 0xa8,0x40);
  }
  if ((u32)(*(int *)(param_1 + 0xbc) << 5) < 0x40) {
    FUN_0005f230(param_1 + 0xb4,0x40);
  }
}
