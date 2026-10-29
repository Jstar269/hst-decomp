/* HSTMATCH module=EBOOT.BIN start=0x001e71c4 end=0x001e722c symbol=FUN_001e71c4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/result_page.h"

extern void FUN_00103628();
extern void FUN_001e2694();
extern void FUN_001e722c();

void FUN_001e71c4(ResultPage *page,int param_2,int param_3,int param_4)
{
  FUN_001e2694(page);
  FUN_00103628(page->lay810,0);
  FUN_001e722c(page,param_2,param_3,param_4);
}
