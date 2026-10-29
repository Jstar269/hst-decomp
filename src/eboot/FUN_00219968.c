/* HSTMATCH module=EBOOT.BIN start=0x00219968 end=0x00219998 symbol=FUN_00219968 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vec.h"

extern void FUN_00022418();

/* dst += src (4-float vectors). */
Float4 * FUN_00219968(Float4 *dst,const Float4 *src)
{
  FUN_00022418(dst,dst,src);
  return dst;
}
