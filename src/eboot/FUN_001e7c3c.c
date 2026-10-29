/* HSTMATCH module=EBOOT.BIN start=0x001e7c3c end=0x001e7c64 symbol=FUN_001e7c3c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/result_page.h"

extern void FUN_00103628();

void FUN_001e7c3c(ResultPage *page)
{
  if (page->lay2464 != 0) {
    FUN_00103628(page->lay2464,1);
  }
}
