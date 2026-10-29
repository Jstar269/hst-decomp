/* HSTMATCH module=hstp_trans_main.prx start=0x001f5f08 end=0x001f5f40 symbol=FUN_001f5f08 lang=c99 */
/* Clone of src/eboot/FUN_001e7cf0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/result_page.h"

extern void FUN_00226954();

void FUN_001f5f08(ResultPage *page)
{
  FUN_00226954(page->unk252c,0x80,0,10);
  page->unk2528 = 0;
}
