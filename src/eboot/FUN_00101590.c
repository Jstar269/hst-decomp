/* HSTMATCH module=EBOOT.BIN start=0x00101590 end=0x00101630 symbol=FUN_00101590 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/draw_list.h"

extern void FUN_00101798(DrawList *list,int frame,int part,u32 x,u32 y, u32 colorA,u32 colorB);
extern void FUN_00107174(RawVec *queue,u32 count);

/* One entry of the input array: frame, part, x and y offsets, and two more words. */
typedef struct DrawEntry {
  u32 frame;     /* 0x00 */
  u32 part;      /* 0x04 */
  short x;       /* 0x08 */
  short y;       /* 0x0a */
  short colorA;  /* 0x0c */
  char pad0e[2];
  u32 colorB;    /* 0x10 */
} DrawEntry;

/* Reserve room for count entries in the queue (when it is still empty), then draw each entry. */
void FUN_00101590(DrawList *list,DrawEntry *entries,u32 count)
{
  int i;

  if ((list->queue.size == 0) && (list->queue.capacity < count)) {
    FUN_00107174(&list->queue,(u32)(count));
  }
  i = 0;
  if (0 < (int)count) {
    do {
      FUN_00101798(list,(int)(entries->frame),(int)(entries->part),(u32)((int)entries->x),(u32)((int)entries->y),(u32)((int)entries->colorA),(u32)(entries->colorB));
      i = i + 1;
      entries = entries + 1;
    } while (i < (int)count);
  }
}
