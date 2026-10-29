/* HSTMATCH module=hstp_trans_main.prx start=0x001f5ec0 end=0x001f5f08 symbol=FUN_001f5ec0 lang=c99 */
/* Clone of src/eboot/FUN_001e7ca8.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/result_page.h"

extern void FUN_00108f54();
extern void FUN_00226954();

void FUN_001f5ec0(ResultPage *page)
{
  FUN_00108f54(page->lose_lay,0);
  FUN_00226954(page->unk252c,0,0x80,10);
  page->unk2528 = 0x46;
}
