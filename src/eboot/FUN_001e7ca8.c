/* HSTMATCH module=EBOOT.BIN start=0x001e7ca8 end=0x001e7cf0 symbol=FUN_001e7ca8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/result_page.h"

extern void FUN_00103628();
extern void FUN_002178ac();

void FUN_001e7ca8(ResultPage *page)
{
  FUN_00103628(page->lose_lay,0);
  FUN_002178ac(page->unk252c,0,0x80,10);
  page->unk2528 = 0x46;
}
