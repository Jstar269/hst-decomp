/* HSTMATCH module=EBOOT.BIN start=0x0009265c end=0x00092720 symbol=FUN_0009265c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag v21) corrected by hand: typed the string lookup and dispatch prototypes, used the null-result ternary, and expressed the final negative exit; readability pass; exact match verified; names and types await human review. */

#include "hst/char_model.h"

extern char DAT_002d2930[];
extern char DAT_002d294c[];
extern int FUN_0002fe80(struct List *list,char *name);
extern void FUN_00054464(ModelCtrl *ctrl,int unk,int bone,int value,int flags);

/* Looks up two named bones on item 5's controller and sends each a value:
   the first the inverse of show, the second show itself. */
void FUN_0009265c(CharModel *self,int show)
{
  ModelCtrl *ctrl;
  struct List *list;
  int bone;
  
  if ((self->item[5] != 0) &&
     (ctrl = self->item[5]->ctrl, ctrl != 0)) {
    list = ctrl->list;
    bone = list != 0 ? FUN_0002fe80(list,DAT_002d2930) : -1;
    if (bone >= 0) {
      FUN_00054464(self->item[5]->ctrl,-1,bone,(show != 0) ^ 1,0);
    }
    list = self->item[5]->ctrl->list;
    bone = list != 0 ? FUN_0002fe80(list,DAT_002d294c) : -1;
    if (bone < 0) goto done;
    FUN_00054464(self->item[5]->ctrl,-1,bone,show,0);
  }
done:
  return;
}
