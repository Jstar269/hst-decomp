/* HSTMATCH module=EBOOT.BIN start=0x00127a20 end=0x00127a68 symbol=FUN_00127a20 lang=c99 */
/* Hand-written reconstruction (external matching lane); exact match verified; names and types await human review. */
/* Ghidra pseudocode (hstgen.py) corrected by hand: OR chain written as an assignment chain (`if (!b) b = ...; return b;`) to get the xor/sltiu/bnez short-circuit; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u32 DAT_0033b528;
extern u32 DAT_0033b52c;
extern u32 DAT_0033b534;

int FUN_00127a20(int param_1)
{
  int b;
  b = param_1 == DAT_0033b528;
  if (!b) b = param_1 == DAT_0033b52c;
  if (!b) b = param_1 == DAT_0033b534;
  return b;
}
