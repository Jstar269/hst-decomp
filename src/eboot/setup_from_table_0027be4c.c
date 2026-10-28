/* HSTMATCH module=EBOOT.BIN start=0x0027be4c end=0x0027bf24 symbol=FUN_0027be4c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

extern char *DAT_0034a7e4;
extern int FUN_0027c774(int, int);
extern void FUN_0027c008(int);
extern void FUN_0027c908(int, int);
extern void FUN_0001f1fc(int, int);

void FUN_0027be4c(int param_1, int param_2, s32 param_3)
{
  int found;
  int i;
  int off;

  *(int *)(param_1 + 0x68) = param_3;
  *(int *)(param_1 + 0x60) = 0;
  *(int *)(param_1 + 0x74) = 0;
  found = -1;
  for (i = 0, off = 0; i < 0x80; i++, off += 0x40) {
    if (param_2 == *(int *)(DAT_0034a7e4 + off + 0x30)
        && 0 < *(int *)(DAT_0034a7e4 + off + 0x3c)) {
      found = FUN_0027c774(param_1, i);
      if (0 <= found)
        break;
    }
  }
  *(int *)(param_1 + 0x54) = -1;
  FUN_0027c008(param_1);
  FUN_0027c908(param_1, found);
  FUN_0001f1fc(param_1, 1);
  *(u8 *)(param_1 + 0x64) = 1;
}
