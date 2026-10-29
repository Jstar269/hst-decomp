/* HSTMATCH module=EBOOT.BIN start=0x001e5ac4 end=0x001e5b64 symbol=FUN_001e5ac4 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/result_widgets.h"

extern "C" {
extern void FUN_00103628(...);
extern void FUN_001e2694(...);
extern void FUN_001e5b64(...);
}

/* Widget with a virtual setter taking one int (vtable slot 1). */
struct Widget { virtual void d0(); virtual void m(int); };

struct ResultPage {
  char pad00[0x1d68];
  void *list;                            /* 0x1d68 */
  Widget *widget[RESULT_WIDGET_COUNT];   /* 0x1d6c */
};

/* Free the owned objects, then call every widget's setter with 0 (the last one with 1). */
extern "C" void FUN_001e5ac4(ResultPage *page)
{
  FUN_001e2694();
  FUN_00103628(page->list,0);
  page->widget[0]->m(0);
  page->widget[1]->m(0);
  page->widget[2]->m(0);
  page->widget[3]->m(0);
  page->widget[4]->m(1);
  FUN_001e5b64(page,0);
}
