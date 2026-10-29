/* HSTMATCH module=EBOOT.BIN start=0x00181284 end=0x001813a0 symbol=FUN_00181284 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/view_rect.h"

typedef struct PaneOwner { char pad[0x10d4]; PaneRect *rect; } PaneOwner;
extern void *DAT_003313c4;
extern void *DAT_00341518;
extern void FUN_0005bbd4(void *, float, float, float, float, float, float);
extern void FUN_0005bc58(ViewWords *);
extern ViewWords *FUN_00179700(void *);

void FUN_00181284(PaneOwner *self)
{
  PaneRect *r = self->rect;
  short center_x = (short)((r->left + r->right) / 2);
  short center_y = (short)((r->top + r->bottom) / 2);
  FUN_0005bbd4(DAT_003313c4, 0.0f, 0.0f, 480.0f, 272.0f,
               (float)center_x, (float)center_y);
  ViewWords *view = FUN_00179700(DAT_00341518);
  view->words[VIEW_WORD_MODE_B] = VIEW_MODE_B_VALUE;
  view->words[VIEW_WORD_MODE_A] = VIEW_MODE_A_VALUE;
  view->words[0] = 0;
  view->words[1] = 0;
  view->words[2] = 0x3f800000;
  view->words[3] = 0x3f800000;
  view->words[4] = 0;
  view->words[5] = 0;
  view->words[6] = 0xbf800000;
  view->words[7] = 0;
  FUN_0005bbd4(view, 0.0f, 0.0f, 480.0f, 272.0f,
               (float)center_x, (float)center_y);
  FUN_0005bc58(view);
}
