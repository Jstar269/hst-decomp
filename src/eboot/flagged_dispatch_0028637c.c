/* HSTMATCH module=EBOOT.BIN start=0x0028637c end=0x002863e4 symbol=FUN_0028637c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag from inputs/generated/FUN_0028637c.c) corrected by hand: three further incoming arguments forwarded unchanged to the callee, which keeps a1-a3 live so the context pointer lands in t0; readability pass; exact match verified; names and types await human review. */
#include "hst/screen_mgr.h"

extern ScreenMgr *DAT_003415ac;
extern void FUN_002805fc(char *text, int b, int c, int d);

/* matching idiom: arg2..arg4 are only forwarded (Ghidra dropped them) */
void FUN_0028637c(NoticeObj *notice, int arg2, int arg3, int arg4)
{
  notice->unkc5 = 1;
  if (notice->unk4 == 0 &&
      (((*DAT_003415ac->pageList->pages)->flags & 3) != 0 || DAT_003415ac->mode != 6)) {
    FUN_002805fc(notice->text, arg2, arg3, arg4);
  }
}
