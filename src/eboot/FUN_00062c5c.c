/* HSTMATCH module=EBOOT.BIN start=0x00062c5c end=0x00062cb4 symbol=FUN_00062c5c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag g2) corrected by hand: default MWCC profile, s0 >= 0 and nested if; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

extern int FUN_000761a8(int, u32, u32);
extern void FUN_0007771c(int, int);
extern int FUN_000777b4(int);

/* Starts a sound with no source (-1) and returns its handle; a valid handle for which the check returns 0 gets
   FUN_0007771c(handle, 2). */
int FUN_00062c5c(u32 arg_a, u32 arg_b)
{
  int handle = FUN_000761a8(0xffffffff, arg_a, arg_b);
  if (handle >= 0) {
    if (FUN_000777b4(handle) == 0) {
      FUN_0007771c(handle, 2);
    }
  }
  return handle;
}
