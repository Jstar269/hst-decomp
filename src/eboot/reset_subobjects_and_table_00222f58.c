/* HSTMATCH module=EBOOT.BIN start=0x00222f58 end=0x0022305c symbol=FUN_00222f58 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s512a) corrected by hand: typed subobject access in loop, block-scoped counter/pointer in clear loops; readability pass; exact match verified; names and types await human review. */

#include "hst/types.h"
#include "hst/prize_display.h"

#define PRIZE_STATE_ACTIVE 100

extern PrizeRow *DAT_0034a268;
extern PrizeRow *DAT_0034a26c;
extern void FUN_00103480(void);
extern void FUN_0022305c(void);

/* Switch to the active state: reset the pane positions and scale, then hide every row of both row tables. */
void FUN_00222f58(PrizeDisplay *self)
{
  int i;
  
  self->active = 0;
  if (self->alt_layout == 0) {
    FUN_0022305c();
  }
  else {
    self->state = PRIZE_STATE_ACTIVE;
    for (i = 0; i < PRIZE_PANE_COUNT; i++) {
      if (self->panes[i] != 0) {
        if (i == 0) {
          self->panes[i]->x = self->base_x;
          self->panes[i]->y = self->base_y;
        }
        self->panes[i]->scale = 1.0f;
      }
    }

    FUN_00103480();
    
    {
      int j = 0;
      PrizeRow *row = DAT_0034a268;
      do {
        row[0].shown = 0;
        row[1].shown = 0;
        row[2].shown = 0;
        row[3].shown = 0;
        row[4].shown = 0;
        row[5].shown = 0;
        row[6].shown = 0;
        j = j + 8;
        row[7].shown = 0;
        row = row + 8;
      } while (j < PRIZE_ROW_COUNT);
    }

    {
      int j = 0;
      PrizeRow *row = DAT_0034a26c;
      do {
        row[0].shown = 0;
        row[1].shown = 0;
        row[2].shown = 0;
        row[3].shown = 0;
        row[4].shown = 0;
        row[5].shown = 0;
        row[6].shown = 0;
        j = j + 8;
        row[7].shown = 0;
        row = row + 8;
      } while (j < PRIZE_ROW_COUNT);
    }
  }
}
