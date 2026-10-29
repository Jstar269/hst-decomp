/* HSTMATCH module=EBOOT.BIN start=0x002862a8 end=0x0028637c symbol=FUN_002862a8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/screen_mgr.h"
#include "hst/text_bank_lookup.h"

extern ScreenMgr *DAT_003415ac;
extern void FUN_00114168(ScreenMgr *, int, const char *, int, int);
extern TextBank *FUN_0018c9f4(int);

/* Variant of FUN_002861e0 that also requires the notice's flag byte to be clear, with message 18. */
void FUN_002862a8(NoticeObj *notice)
{
  notice->unkc5 = 1;
  if (notice->unk4 == 0 &&
      (((*DAT_003415ac->pageList->pages)->flags & 3) != 0 || DAT_003415ac->mode != 6)) {
    FUN_00114168(DAT_003415ac, 6, TextGet(FUN_0018c9f4(TEXT_BANK_MESSAGES), 16, 18), 0, 0);
  }
}
