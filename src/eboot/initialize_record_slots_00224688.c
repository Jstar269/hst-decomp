/* HSTMATCH module=EBOOT.BIN start=0x00224688 end=0x00224738 symbol=FUN_00224688 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: declared the loop counter before the cursor; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/page_menu.h"

extern void FUN_00224738();
extern void FUN_00224830();

/* Reset the menu: select entry 0, clear both value-block sets, then seed the first block of each set. */
void FUN_00224688(PageMenu *menu)
{
  int i;
  PageMenu *cursor; /* advances one block (8 words) per pass */

  menu->cursor = 0;
  menu->count = PAGE_MENU_ENTRIES;
  FUN_00224738(menu,menu->cursor);
  menu->unk118 = 0;
  i = 0;
  cursor = menu;
  do {
    *(u32 *)&cursor->block[0][0][0] = 0;
    *(u32 *)&cursor->block[1][0][0] = 0;
    *(u32 *)&cursor->block[0][0][1] = 0;
    *(u32 *)&cursor->block[1][0][1] = 0;
    *(u32 *)&cursor->block[0][0][2] = 0;
    *(u32 *)&cursor->block[1][0][2] = 0;
    *(u32 *)&cursor->block[0][0][3] = 0;
    *(u32 *)&cursor->block[1][0][3] = 0;
    *(u32 *)&cursor->block[0][0][4] = 0;
    *(u32 *)&cursor->block[1][0][4] = 0;
    *(u32 *)&cursor->block[0][0][5] = 0;
    *(u32 *)&cursor->block[1][0][5] = 0;
    *(u32 *)&cursor->block[0][0][6] = 0;
    *(u32 *)&cursor->block[1][0][6] = 0;
    *(u32 *)&cursor->block[0][0][7] = 0;
    i = i + PAGE_MENU_BLOCK_WORDS;
    *(u32 *)&cursor->block[1][0][7] = 0;
    cursor = (PageMenu *)((char *)cursor + PAGE_MENU_BLOCK_WORDS * 4);
  } while (i < 2 * PAGE_MENU_BLOCK_WORDS);
  menu->block[0][0][0] = 50.0f;
  menu->block[1][0][0] = 50.0f;
  menu->block[0][0][1] = 240.0f;
  menu->block[1][0][1] = 50.0f;
  FUN_00224830(menu);
}
