/* HSTMATCH module=EBOOT.BIN start=0x000b939c end=0x000b9450 symbol=FUN_000b939c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: changed FUN_000487c8 return type from bool to int to preserve retail integer testing; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 * DAT_002cfc8c;
extern u8 * DAT_003386b0;
extern u32 DAT_00338c20;
extern u8 * DAT_00341ccc;
extern int FUN_000487c8();
extern void FUN_000b8118();
extern void FUN_000b94b8();
extern u32 FUN_000fb7b8();

void FUN_000b939c(int param_1)
{
  int iVar1;
  
  if ((((((int)*(char *)(DAT_002cfc8c + 0x88) << 0x1e) >> 0x1e == 0) &&
       (iVar1 = FUN_000487c8(), iVar1 == 0)) && (iVar1 = FUN_000fb7b8(DAT_00338c20), iVar1 == 0))
     && (*(int *)(DAT_003386b0 + 0x3c) == 4)) {
    iVar1 = (*(int *)(param_1 + 0x68) + 1) % 3;
    *(int *)(param_1 + 0x68) = iVar1;
    *(char *)(DAT_00341ccc + 0x1052) = (char)iVar1;
    *(u32 *)(param_1 + 100) = *(u32 *)(param_1 + 0x68);
    FUN_000b8118(param_1);
  }
  FUN_000b94b8(param_1);
}

