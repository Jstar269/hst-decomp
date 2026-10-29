/* HSTMATCH module=hstp_trans_main.prx start=0x00106f68 end=0x00107008 symbol=FUN_00106f68 lang=c99 */
/* Clone of src/eboot/FUN_00101590.c (hstclone.py tag x2): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/draw_list.h"

extern void FUN_00107170(DrawList *list,int frame,int part,u32 x,u32 y, u32 colorA,u32 colorB);
extern void FUN_0010cf34(RawVec *queue,u32 count);

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
void FUN_00106f68(DrawList *list,DrawEntry *entries,u32 count)
{
  int i;

  if ((list->queue.size == 0) && (list->queue.capacity < count)) {
    FUN_0010cf34(&list->queue,(u32)(count));
  }
  i = 0;
  if (0 < (int)count) {
    do {
      FUN_00107170(list,(int)(entries->frame),(int)(entries->part),(u32)((int)entries->x),(u32)((int)entries->y),(u32)((int)entries->colorA),(u32)(entries->colorB));
      i = i + 1;
      entries = entries + 1;
    } while (i < (int)count);
  }
}
