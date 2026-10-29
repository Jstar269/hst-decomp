/* HSTMATCH module=EBOOT.BIN start=0x0010b29c end=0x0010b308 symbol=FUN_0010b29c lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/mode_list.h"

/* Return the highlighted one of the three shown items. */
ModeItem * FUN_0010b29c(ModeList *self)
{
  int first;

  first = self->first;
  switch (self->mode) {
  case 1:
    return self->items[first];
  case 2:
    return *(ModeItem **)((char *)self->items + (first + 2) * 4);
  case 0:
  default:
    return *(ModeItem **)((char *)self->items + (first + 1) * 4);
  }
}
