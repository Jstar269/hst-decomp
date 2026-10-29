/* HSTMATCH module=EBOOT.BIN start=0x0010b150 end=0x0010b29c symbol=FUN_0010b150 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mode_list.h"

extern void FUN_000ffb3c(ModeItem *, int);

/* Of the three shown items, clear the flag on the highlighted one (chosen by mode) and set it on the other two. */
void FUN_0010b150(ModeList *self)
{
  int first;

  first = self->first;
  switch (self->mode) {
  case 1:
    FUN_000ffb3c(self->items[first],0);
    FUN_000ffb3c(*(ModeItem **)((char *)self->items + (first + 1) * 4),1);
    FUN_000ffb3c(*(ModeItem **)((char *)self->items + (first + 2) * 4),1);
    break;
  case 2:
    FUN_000ffb3c(*(ModeItem **)((char *)self->items + (first + 2) * 4),0);
    FUN_000ffb3c(self->items[first],1);
    FUN_000ffb3c(*(ModeItem **)((char *)self->items + (first + 1) * 4),1);
    break;
  case 0:
  default:
    FUN_000ffb3c(*(ModeItem **)((char *)self->items + (first + 1) * 4),0);
    FUN_000ffb3c(self->items[first],1);
    FUN_000ffb3c(*(ModeItem **)((char *)self->items + (first + 2) * 4),1);
    break;
  }
}
