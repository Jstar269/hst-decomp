/* HSTMATCH module=EBOOT.BIN start=0x00196ef4 end=0x00197208 symbol=FUN_00196ef4 lang=c++ rodata=0x002c28a0 */
/* Hand-written reconstruction from the disassembly; matching idioms: dense 0..13 switch (rodata=0x002c28a0) with case 0 ending in 'continue' (the others 'break'), counter spr_count declared before the loop counter, the sprite slot read as self->spr[spr_count] with 'spr_count++' as the LAST statement of case 7, int (not short) arithmetic in the rect stores; exact match verified; names and types await human review. */
#include "hst/rect_page.h"

extern "C" {
void FUN_00103628(PageDev *, int);
void FUN_00196aac(RectPage *, int *, int *, int, int, RectEntry *);
void FUN_00196c6c(RectPage *, int *, int *, int, RectEntry *);
void FUN_000ffb3c(RectElem *, int);
}

/* Walk the queued entries and hand each one to the placement helper for its type (or set up a sprite element directly for type 7), then clear the queue. */
extern "C" void FUN_00196ef4(RectPage *self)
{
  FUN_00103628(self->dev, 1);
  int unk34_count = 0;
  int wide_count = 0;
  int small_count = 0;
  int spr_count = 0;
  int i;
  for (i = 0; i < self->count; i++) {
    RectEntry *e = &self->ent[i];
    switch (e->type) {
    case 0:
      FUN_00196aac(self, &unk34_count, &wide_count, 0, 4, e);
      continue;
    case 1:
      FUN_00196aac(self, &unk34_count, &wide_count, 2, 4, e);
      break;
    case 2:
      FUN_00196aac(self, &unk34_count, &wide_count, 1, 4, e);
      break;
    case 3:
      FUN_00196aac(self, &unk34_count, &wide_count, 3, 4, e);
      break;
    case 4:
      FUN_00196aac(self, &unk34_count, &wide_count, 4, 5, e);
      break;
    case 5:
      FUN_00196aac(self, &unk34_count, &wide_count, 5, 6, e);
      break;
    case 6:
      FUN_00196c6c(self, &small_count, &wide_count, 10, e);
      break;
    case 7:
      if (spr_count < RECT_PAGE_SMALL) {
        RectElem *o = self->spr[spr_count];
        FUN_000ffb3c(o, 0);
        o->x = e->x;
        o->y = e->y - 3;
        o->x2 = o->x + (int)(20.0f * e->w);
        o->y2 = o->y + (int)(20.0f * e->h);
        spr_count++;
      }
      break;
    case 8:
      FUN_00196c6c(self, &small_count, &wide_count, 0, e);
      break;
    case 9:
      FUN_00196c6c(self, &small_count, &wide_count, 3, e);
      break;
    case 10:
      FUN_00196c6c(self, &small_count, &wide_count, 2, e);
      break;
    case 11:
      FUN_00196c6c(self, &small_count, &wide_count, 1, e);
      break;
    case 12:
      FUN_00196aac(self, &unk34_count, &wide_count, 6, 7, e);
      break;
    case 13:
      FUN_00196aac(self, &unk34_count, &wide_count, 7, 8, e);
      break;
    }
  }
  if (self->count > 0) self->dev->m3();
  self->count = 0;
}
