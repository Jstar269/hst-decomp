/* HSTMATCH module=EBOOT.BIN start=0x0019167c end=0x001916a4 symbol=FUN_0019167c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

/* Four-word record. */
typedef struct Words4 {
  u32 w0; /* 0x0 */
  u32 w1; /* 0x4 */
  u32 w2; /* 0x8 */
  u32 w3; /* 0xc */
} Words4;

/* Copies the four words field by field and returns the destination. */
Words4 * FUN_0019167c(Words4 *dst,Words4 *src)
{
  dst->w0 = src->w0;
  dst->w1 = src->w1;
  dst->w2 = src->w2;
  dst->w3 = src->w3;
  return dst;
}
