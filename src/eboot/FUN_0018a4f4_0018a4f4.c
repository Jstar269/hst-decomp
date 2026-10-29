/* HSTMATCH module=EBOOT.BIN start=0x0018a4f4 end=0x0018a5a0 symbol=FUN_0018a4f4 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/layout_list.h"

extern void FUN_002174bc(void *);

/* Place every item of the list: write its quad's rectangle from the list origin, item offset and list size. */
void FUN_0018a4f4(LayoutList *self, LayoutItem *item)
{
  int count;
  int i;

  FUN_002174bc(&self->vtableD0);
  i = 0;
  if (0 < self->count) {
    do {
      if (item->quad != 0) {
        int x = self->originX + item->x;
        int y = self->originY + self->scrollY + item->y;
        item->quad->left = x;
        item->quad->right = x + self->width;
        item->quad->top = y;
        item->quad->bottom = y + self->height;
      }
      count = self->count;
      ++i;
      item++;
    } while (i < count);
  }
}
