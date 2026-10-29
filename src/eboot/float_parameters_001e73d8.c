/* HSTMATCH module=EBOOT.BIN start=0x001e73d8 end=0x001e744c symbol=FUN_001e73d8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed the mixed integer and float helper parameters and passed the pointer and float values in declared order; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/fx_page.h"

extern char DAT_002ec180[];
extern u32 FUN_00065740();
extern int FUN_001ee224();
extern void FUN_0021780c(void *,int,float,float);
extern void FUN_00217834();

void FUN_001e73d8(FxPage *page)
{
  u32 handle;
  
  handle = FUN_001ee224();
  handle = FUN_00065740(handle,DAT_002ec180,1);
  FUN_00217834(page->fx,page->fx_arg,0xffffffff,handle);
  FUN_0021780c(page->fx,handle,1.5f,1.0f);
}
