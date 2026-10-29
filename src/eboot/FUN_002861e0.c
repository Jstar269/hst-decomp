/* HSTMATCH module=EBOOT.BIN start=0x002861e0 end=0x002862a8 symbol=FUN_002861e0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/screen_mgr.h"
#include "hst/text_bank_lookup.h"

extern ScreenMgr *DAT_003415ac;
extern void FUN_00114168(ScreenMgr *, int, const char *, int, int);
extern TextBank *FUN_0018c9f4(int);

/* Marks the notice queued and, unless the top page is idle in mode 6, shows message 16 of group 16. */
void FUN_002861e0(NoticeObj *notice)
{
  notice->unkc5 = 1;
  if (((*DAT_003415ac->pageList->pages)->flags & 3) != 0 || DAT_003415ac->mode != 6) {
    FUN_00114168(DAT_003415ac, 6, TextGet(FUN_0018c9f4(TEXT_BANK_MESSAGES), 16, 16), 0, 0);
  }
}
