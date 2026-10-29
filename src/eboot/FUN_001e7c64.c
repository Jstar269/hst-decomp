/* HSTMATCH module=EBOOT.BIN start=0x001e7c64 end=0x001e7ca8 symbol=FUN_001e7c64 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/result_page.h"

extern void FUN_00103628();

void FUN_001e7c64(ResultPage *page,int flag)
{
  FUN_00103628(page->lose_lay);
  if (flag == 0) {
    page->unk2528 = 0x3c;
  }
  else {
    page->unk2528 = 0;
  }
}
