/* HSTMATCH module=EBOOT.BIN start=0x00288a84 end=0x00288af0 symbol=FUN_00288a84 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/mode_obj.h"

/* The mode object sits this many bytes into the object that contains it. */
enum { CONTAINER_OFFSET = 0xe0 };

/* In mode 2 or 3 return the containing object (null stays null), otherwise null. */
extern "C" int *FUN_00288a84(VirtualModeObj *self)
{
  int mode;
  bool match;
  int *result = (int *)self;
  mode = self->mode();
  match = mode == 2;
  if (!match) {
    mode = self->mode();
    match = mode == 3;
  }
  if (match) {
    if (result != (int *)0) result = (int *)((char *)result - CONTAINER_OFFSET);
  } else {
    return (int *)0;
  }
  return result;
}
