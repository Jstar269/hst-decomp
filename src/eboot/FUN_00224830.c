/* HSTMATCH module=EBOOT.BIN start=0x00224830 end=0x00224860 symbol=FUN_00224830 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/page_menu.h"

extern void FUN_00103628();

void FUN_00224830(PageMenu *menu)
{
  FUN_00103628(menu,1);
  menu->unk54 = 1;
}
