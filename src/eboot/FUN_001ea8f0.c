/* HSTMATCH module=EBOOT.BIN start=0x001ea8f0 end=0x001ea930 symbol=FUN_001ea8f0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/two_quad_screen.h"

/* Resets both records of the screen to -1 and clears a flag byte. */
void FUN_001ea8f0(TwoQuadRef *ref)
{
  TwoQuadScreen *screen;
  int i;
  TwoQuadScreen *cur;
  
  screen = ref->screen;
  i = 0;
  cur = screen;  /* stepped by one record per pass, so record[0] is the current record */
  do {
    cur->record[0][0] = -1;
    cur->record[0][1] = -1;
    cur->record[0][2] = -1;
    cur->record[0][3] = -1;
    cur->record[0][4] = -1;
    i = i + 1;
    cur->record[0][5] = -1;
    cur = (TwoQuadScreen *)((char *)cur + sizeof(cur->record[0]));
  } while (i < TWO_QUAD_PAIR_COUNT);
  screen->unk418 = 0;
}
