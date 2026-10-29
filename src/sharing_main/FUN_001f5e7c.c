/* HSTMATCH module=hstp_trans_main.prx start=0x001f5e7c end=0x001f5ec0 symbol=FUN_001f5e7c lang=c99 */
/* Clone of src/eboot/FUN_001e7c64.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/result_page.h"

extern void FUN_00108f54();

void FUN_001f5e7c(ResultPage *page,int flag)
{
  FUN_00108f54(page->lose_lay);
  if (flag == 0) {
    page->unk2528 = 0x3c;
  }
  else {
    page->unk2528 = 0;
  }
}
