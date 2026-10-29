/* HSTMATCH module=EBOOT.BIN start=0x00112e10 end=0x00112ed8 symbol=FUN_00112e10 lang=c99 data=0x002d92ec */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review.
   The `digits->stride > 15` spelling is needed for retail's `slti at`/`bnezl at` (writing `>= 0x10` puts the
   compare in v1); `i = 0` is initialised before the `0 < count` guard and the source-cell index is computed
   before the -999 test so its multiply lands in the likely-branch delay slot. Data: its string literals (2 strings, 0x002d92ec-0x002d935e) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#pragma opt_strength_reduction off
#include "hst/progress_digits.h"
extern void FUN_00112c94(char *, ...);

/* Store first/stride/count; check that the sprite set is not empty and the stride fits, then read each unset cell value from its sprite cell. */
void FUN_00112e10(ProgressDigits *digits, int first, int stride, int count)
{
  int i;
  int idx;
  int *p;

  digits->first = first;
  digits->stride = stride;
  digits->count = count;
  if (digits->host->count < 1) {
    FUN_00112c94("ERROR: DigitForProgressBar::Init(): sprite not found.\n");
  }
  else if (digits->stride > PROGRESS_DIGITS_MAX) {
    FUN_00112c94("ERROR: DigitForProgressBar::Init(): too many sprite num.\n");
  }
  else {
    i = 0;
    if (0 < count) {
    p = (int *)digits;
    do {
      int idx = digits->first + i * digits->stride;
      if (p[4] == PROGRESS_DIGIT_UNSET) {
        p[4] = digits->host->cells[idx]->value;
      }
      digits->unk5b[i] = 0;
      digits->unk6a[i] = 0;
      i = i + 1;
      p = p + 1;
    } while (i < count);
    }
  }
  return;
}
