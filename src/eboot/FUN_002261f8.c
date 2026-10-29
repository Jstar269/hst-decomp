/* HSTMATCH module=EBOOT.BIN start=0x002261f8 end=0x0022621c symbol=FUN_002261f8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

/* Gathers four words, each read through its own pointer, into a four-word record. */
void FUN_002261f8(u32 *dst,u32 *src0,u32 *src1,u32 *src2, u32 *src3)
{
  *dst = *src0;
  dst[1] = *src1;
  dst[2] = *src2;
  dst[3] = *src3;
}
