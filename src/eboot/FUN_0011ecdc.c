/* HSTMATCH module=EBOOT.BIN start=0x0011ecdc end=0x0011ed04 symbol=FUN_0011ecdc lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

/* Four words copied as plain integers. */
typedef struct Words4 {
  u32 w[4];
} Words4;

/* Copies a 16-byte record word by word; returns dst. */
Words4 * FUN_0011ecdc(Words4 *dst,Words4 *src)
{
  dst->w[0] = src->w[0];
  dst->w[1] = src->w[1];
  dst->w[2] = src->w[2];
  dst->w[3] = src->w[3];
  return dst;
}
