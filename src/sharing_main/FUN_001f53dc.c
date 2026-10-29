/* HSTMATCH module=hstp_trans_main.prx start=0x001f53dc end=0x001f5444 symbol=FUN_001f53dc lang=c99 */
/* Clone of src/eboot/FUN_001e71c4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/result_page.h"

extern void FUN_00108f54();
extern void FUN_001f08e8();
extern void FUN_001f5444();

void FUN_001f53dc(ResultPage *page,int param_2,int param_3,int param_4)
{
  FUN_001f08e8(page);
  FUN_00108f54(page->lay810,0);
  FUN_001f5444(page,param_2,param_3,param_4);
}
