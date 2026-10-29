/* HSTMATCH module=EBOOT.BIN start=0x001016f4 end=0x00101798 symbol=FUN_001016f4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/draw_list.h"

extern void FUN_00101798();
extern void FUN_00107174();

/* One entry of the input array: frame id and a second id, with a word between them. */
typedef struct FrameRef {
  u32 frame;     /* 0x00 */
  u32 unk4;      /* 0x04 */
  u32 part;      /* 0x08 */
} FrameRef;

enum { ALL_ONES = 0xffffffff, HALF_BYTES = 0x80808080 };

/* Reserve room for count entries in the queue (when it is still empty), then draw each entry at the origin. */
void FUN_001016f4(DrawList *list,FrameRef *refs,u32 count)
{
  int i;

  if ((list->queue.size == 0) && (list->queue.capacity < count)) {
    FUN_00107174(&list->queue,count);
  }
  i = 0;
  if (0 < (int)count) {
    do {
      FUN_00101798(list,refs->frame,refs->part,0,0,ALL_ONES,HALF_BYTES);
      i = i + 1;
      refs = refs + 1;
    } while (i < (int)count);
  }
}
