/* HSTMATCH module=hstp_trans_main.prx start=0x001f3cdc end=0x001f3d7c symbol=FUN_001f3cdc lang=c++ */
/* Clone of src/eboot/FUN_001e5ac4.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/result_widgets.h"

extern "C" {
extern void FUN_00108f54(...);
extern void FUN_001f08e8(...);
extern void FUN_001f3d7c(...);
}

/* Widget with a virtual setter taking one int (vtable slot 1). */
struct Widget { virtual void d0(); virtual void m(int); };

struct ResultPage {
  char pad00[0x1d68];
  void *list;                            /* 0x1d68 */
  Widget *widget[RESULT_WIDGET_COUNT];   /* 0x1d6c */
};

/* Free the owned objects, then call every widget's setter with 0 (the last one with 1). */
extern "C" void FUN_001f3cdc(ResultPage *page)
{
  FUN_001f08e8();
  FUN_00108f54(page->list,0);
  page->widget[0]->m(0);
  page->widget[1]->m(0);
  page->widget[2]->m(0);
  page->widget[3]->m(0);
  page->widget[4]->m(1);
  FUN_001f3d7c(page,0);
}
