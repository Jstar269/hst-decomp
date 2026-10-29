/* HSTMATCH module=EBOOT.BIN start=0x001e7bc0 end=0x001e7c3c symbol=FUN_001e7bc0 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/result_page.h"

extern "C" {
extern void FUN_00103628(...);
extern void FUN_001e09dc(...);
extern void FUN_001e2694(...);
}
struct ResultSwitch { virtual void d0(); virtual void m(int); };

/* Page start: both switches on, then the score pair is set one past its second value. */
extern "C" void FUN_001e7bc0(ResultPage *page)
{
  ResultSwitch *sw;
  
  FUN_001e09dc(page,2);
  sw = page->ui->unk58;
  sw->m(1);
  sw = page->ui->unk5c;
  sw->m(1);
  FUN_001e2694(page);
  FUN_00103628(page->lay2464,0);
  page->score_box->unk24 = page->score_box->unk28 + 1;
}
