/* HSTMATCH module=EBOOT.BIN start=0x00216e70 end=0x00216e90 symbol=FUN_00216e70 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/color_words.h"

/* Narrow the three channel words to bytes and add the alpha byte. */
void FUN_00216e70(ColorBytes *dst,ColorWords *src,u8 alpha)
{
  u32 green;
  u32 blue;
  
  blue = src->b;
  green = src->g;
  dst->r = (char)src->r;
  dst->g = (char)green;
  dst->b = (char)blue;
  dst->a = alpha;
}
