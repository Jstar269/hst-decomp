/* HSTMATCH module=EBOOT.BIN start=0x0021aabc end=0x0021ab00 symbol=FUN_0021aabc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: retained and passed the allocated pointer through initialization before one shared store; exact match verified; names and types await human review. */
#include "hst/types.h"
extern u32 *FUN_00000bcc(int);
extern u32 *FUN_00219fa0(u32 *);
void FUN_0021aabc(u32 **param_1)
{
  u32 *p;
  p = FUN_00000bcc(0x114);
  if (p != 0) p = FUN_00219fa0(p);
  *param_1 = p;
}