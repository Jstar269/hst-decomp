/* HSTMATCH module=EBOOT.BIN start=0x001e744c end=0x001e74d4 symbol=FUN_001e744c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/fx_page.h"

extern int FUN_001ee224();
extern int FUN_00065740(int, const char *, int);
extern void FUN_00217834(void *, unsigned, int, int);
extern char DAT_002ec18c[];

void FUN_001e744c(FxPage *page)
{
  int fx_arg = page->fx_arg;
  /* pack the four tint bytes as 0xAABBGGRR */
  unsigned tint = (unsigned)page->tint_a << 24 |
                  (unsigned)page->tint_b << 16 |
                  (unsigned)page->tint_g << 8 |
                  (unsigned)page->tint_r;
  int handle = FUN_001ee224();
  handle = FUN_00065740(handle, DAT_002ec18c, 1);
  FUN_00217834(page->fx, tint, fx_arg, handle);
}
