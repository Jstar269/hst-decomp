/* HSTMATCH module=EBOOT.BIN start=0x00147430 end=0x001474c0 symbol=FUN_00147430 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: the first copied field typed int (the rest are floats); readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct FloatBlock {
  int unk0;         /* 0x00 */
  char pad04[0xc];
  float values[16]; /* 0x10 */
} FloatBlock;

/* Copies the first word and the 16 floats that follow the gap. */
FloatBlock *FUN_00147430(FloatBlock *dst, FloatBlock *src)
{
  dst->unk0 = src->unk0;
  dst->values[0] = src->values[0];
  dst->values[1] = src->values[1];
  dst->values[2] = src->values[2];
  dst->values[3] = src->values[3];
  dst->values[4] = src->values[4];
  dst->values[5] = src->values[5];
  dst->values[6] = src->values[6];
  dst->values[7] = src->values[7];
  dst->values[8] = src->values[8];
  dst->values[9] = src->values[9];
  dst->values[10] = src->values[10];
  dst->values[11] = src->values[11];
  dst->values[12] = src->values[12];
  dst->values[13] = src->values[13];
  dst->values[14] = src->values[14];
  dst->values[15] = src->values[15];
  return dst;
}
