/* HSTMATCH module=EBOOT.BIN start=0x001e7d28 end=0x001e7d70 symbol=FUN_001e7d28 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/result_page.h"

extern void FUN_00103628();
extern void FUN_001e2694();
extern void FUN_001e7d70();
extern u32 FUN_001ee200();

void FUN_001e7d28(ResultPage *page)
{
  FUN_001e2694();
  FUN_00103628(page->overlay_lay,0);
  FUN_001ee200();
  FUN_001e7d70(page,0,0);
}
