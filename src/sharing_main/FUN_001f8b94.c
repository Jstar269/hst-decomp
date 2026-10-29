/* HSTMATCH module=hstp_trans_main.prx start=0x001f8b94 end=0x001f8bd4 symbol=FUN_001f8b94 lang=c99 */
/* Clone of src/eboot/FUN_001ea8f0.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/two_quad_screen.h"

/* Resets both records of the screen to -1 and clears a flag byte. */
void FUN_001f8b94(TwoQuadRef *ref)
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
