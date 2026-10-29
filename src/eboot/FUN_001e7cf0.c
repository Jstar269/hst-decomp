/* HSTMATCH module=EBOOT.BIN start=0x001e7cf0 end=0x001e7d28 symbol=FUN_001e7cf0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/result_page.h"

extern void FUN_002178ac();

void FUN_001e7cf0(ResultPage *page)
{
  FUN_002178ac(page->unk252c,0x80,0,10);
  page->unk2528 = 0;
}
