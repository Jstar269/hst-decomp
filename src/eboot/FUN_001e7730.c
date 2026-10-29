/* HSTMATCH module=EBOOT.BIN start=0x001e7730 end=0x001e7770 symbol=FUN_001e7730 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/result_page.h"

extern u32 FUN_001ee200();

void FUN_001e7730(ResultPage *page)
{
  char *game;
  
  game = (char *)(FUN_001ee200());
  page->unk2350 = *(int *)(game + 0x8178) + 4;
  page->unk2354 = 0xf;
}
