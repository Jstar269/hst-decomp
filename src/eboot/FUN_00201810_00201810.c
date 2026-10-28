/* HSTMATCH module=EBOOT.BIN start=0x00201810 end=0x00201880 symbol=FUN_00201810 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a1) corrected by hand: typed the helper parameters and passed the first field by address; readability pass; exact match verified; names and types await human review. */
#include "hst/menu_rec.h"

extern void FUN_002177d4(void *rec, int x0, int y0, int x1, int y1, int steps);
extern void FUN_00217834(void *rec, u32 colorNoAlpha, u32 color, int steps);

/* The menu object's record array starts at 0x718. */
typedef struct MenuRecs {
  char pad00[0x718];
  Rec8c recs[MENU_REC_COUNT];
} MenuRecs;

/* Starts the entrance moves of records 0 and 2 and the color fade of record 8. */
void FUN_00201810(MenuRecs *obj)
{
  FUN_002177d4(&obj->recs[0], obj->recs[0].x - 0xf0, obj->recs[0].y,
               obj->recs[0].x, obj->recs[0].y, 6);
  FUN_002177d4(&obj->recs[2], obj->recs[2].x, obj->recs[2].y + 0x88,
               obj->recs[2].x, obj->recs[2].y, 6);
  FUN_00217834(&obj->recs[8], obj->recs[8].color & 0xffffff, obj->recs[8].color, 6);
}
