/* HSTMATCH module=EBOOT.BIN start=0x00053f30 end=0x00054010 symbol=FUN_00053f30 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Walks the two nested lists of a scene object (the list head is the member at +8 plus 0x10) and sets or
   clears bit 0x10 of the flag u8 at +0x33 of every leaf item, depending on the mode argument.
   Names provisional. */
#include "hst/types.h"

extern int FUN_0002e840(void *);
extern void *FUN_0002e650(void *, int);
extern int FUN_0002e40c(void *);
extern void *FUN_0002e3d0(void *, int);

#define SCENE_LIST_OFFSET 0x10 /* the list head sits this far into the member at +8 */
#define ITEM_FLAG_MARK 0x10    /* bit set or cleared on every leaf item */

typedef struct {
  char pad[0x33];
  u8 flags; /* 0x33 */
} Item;

void FUN_00053f30(void *self, int mode)
{
  void *list;
  int group_count;
  int i;
  void *group;
  int item_count;
  int j;
  void *slot;
  Item *it;
  list = (char *)*(void **)((char *)self + 8) + SCENE_LIST_OFFSET;
  group_count = FUN_0002e840(list);
  i = 0;
  while (i < group_count) {
    group = FUN_0002e650(list, i);
    item_count = FUN_0002e40c(group);
    j = 0;
    while (j < item_count) {
      slot = FUN_0002e3d0(group, j);
      it = *(Item **)slot;
      if (mode != 0) {
        it->flags |= ITEM_FLAG_MARK;
      } else {
        it->flags &= ~ITEM_FLAG_MARK;
      }
      j++;
    }
    i++;
  }
}
