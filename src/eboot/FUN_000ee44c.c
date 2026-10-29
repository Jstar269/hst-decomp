/* HSTMATCH module=EBOOT.BIN start=0x000ee44c end=0x000ee510 symbol=FUN_000ee44c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag exp-gen3, variant v8) corrected by hand: the hoisted index temporary inlined and the array base written first; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

/* Centre point of a rectangle, stored twice. */
typedef struct RectCenter {
  int x;                        /* 0x00 */
  int y;                        /* 0x04 */
  int x2;                       /* 0x08 same value as x */
  int y2;                       /* 0x0c same value as y */
} RectCenter;

/* Size of a rectangle relative to the 60x28 reference size. */
typedef struct RectScale {
  float x;                      /* 0x00 */
  float y;                      /* 0x04 */
} RectScale;

#define REF_WIDTH 60.0f
#define REF_HEIGHT 28.0f

extern RectScale DAT_002d6cbc[];
extern RectCenter DAT_00338b58[];

/* Stores the centre and relative size of rectangle (x0,y0)-(x1,y1) in entry `index` of both tables. */
void FUN_000ee44c(int index,int x0,int y0,int x1,int y1)
{
  int sumX;
  int sumY;

  sumX = x0 + x1;
  DAT_00338b58[index].x = sumX / 2;
  sumY = y0 + y1;
  DAT_00338b58[index].y = sumY / 2;
  DAT_00338b58[index].x2 = sumX / 2;
  DAT_00338b58[index].y2 = sumY / 2;
  DAT_002d6cbc[index].x = (float)(x1 - x0) / REF_WIDTH;
  DAT_002d6cbc[index].y = (float)(y1 - y0) / REF_HEIGHT;
}
