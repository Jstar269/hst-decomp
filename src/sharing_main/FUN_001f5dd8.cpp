/* HSTMATCH module=hstp_trans_main.prx start=0x001f5dd8 end=0x001f5e54 symbol=FUN_001f5dd8 lang=c++ */
/* Clone of src/eboot/FUN_001e7bc0.cpp (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/result_page.h"

extern "C" {
extern void FUN_00108f54(...);
extern void FUN_001eec00(...);
extern void FUN_001f08e8(...);
}
struct ResultSwitch { virtual void d0(); virtual void m(int); };

/* Page start: both switches on, then the score pair is set one past its second value. */
extern "C" void FUN_001f5dd8(ResultPage *page)
{
  ResultSwitch *sw;
  
  FUN_001eec00(page,2);
  sw = page->ui->unk58;
  sw->m(1);
  sw = page->ui->unk5c;
  sw->m(1);
  FUN_001f08e8(page);
  FUN_00108f54(page->lay2464,0);
  page->score_box->unk24 = page->score_box->unk28 + 1;
}
