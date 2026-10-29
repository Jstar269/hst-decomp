/* HSTMATCH module=EBOOT.BIN start=0x0016461c end=0x001646a0 symbol=FUN_0016461c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/stat_curve.h"

extern StatTable *DAT_00341510; /* curve rows */

/* Distance from the clamped value to the last row, doubled and rounded to an int. */
int FUN_0016461c(int self)
{
  float v = *(float *)(self + 0x50);
  StatCurveRow *rows;
  int count;
  float first;
  float last;
  float clamped;

  rows = (StatCurveRow *)DAT_00341510->base;
  count = DAT_00341510->count;
  first = rows[0].col08;
  last = *(float *)((char *)rows + (count - 1) * STAT_CURVE_ROW_SIZE + 8);
  /* keep v inside [first, last]; the negated upper test is what the retail code emits */
  clamped = v < first ? first : (!(v > last) ? v : last);
  return (int)((last - clamped) * 2.0f + 0.5f);
}
