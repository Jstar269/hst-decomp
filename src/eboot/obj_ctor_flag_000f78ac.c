/* HSTMATCH module=EBOOT.BIN start=0x000f78ac end=0x000f7950 symbol=FUN_000f78ac lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0c) corrected by hand: the if/else flag store is a single store of a bool local (r = DAT == 0x2a; if (r) r = f() != 0), callee returns int; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0030777c;
extern u32 DAT_0034a678;
extern u32 * FUN_00102e38();
extern int FUN_0022c860();

u32 * FUN_000f78ac(u32 *param_1)
{
  int r;
  
  FUN_00102e38();
  *param_1 = (unsigned int)(&DAT_0030777c);
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x18] = 0;
  param_1[0x19] = 0;
  param_1[0x1a] = 0;
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[0x1d] = 0;
  param_1[0x1e] = 0;
  param_1[0x1f] = 0;
  param_1[0x20] = 0;
  param_1[0x21] = 0;
  param_1[0x22] = 0;
  param_1[0x23] = 0;
  param_1[0x24] = 0;
  param_1[0x25] = 0;
  param_1[0x26] = 0;
  r = DAT_0034a678 == 0x2a;
  if (r) {
    r = FUN_0022c860() != 0;
  }
  *(unsigned char *)((int)param_1 + 0x156) = r;
  return param_1;
}
