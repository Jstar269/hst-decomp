/* HSTMATCH module=EBOOT.BIN start=0x001e74d4 end=0x001e750c symbol=FUN_001e74d4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/result_page.h"

extern void FUN_00103628();
extern void FUN_001e2694();
extern void FUN_001e750c();

void FUN_001e74d4(ResultPage *page)
{
  FUN_001e2694();
  FUN_00103628(page->return_lay,0);
  FUN_001e750c(page);
}
