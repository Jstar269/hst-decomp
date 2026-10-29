/* HSTMATCH module=EBOOT.BIN start=0x0027c8a0 end=0x0027c8d0 symbol=FUN_0027c8a0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/blend_obj.h"

extern char *DAT_0034a7e4;

/* Returns overrideB when overrideA is set, else a field of the 64-byte table entry at tableIndex. */
int FUN_0027c8a0(BlendObj *self)
{
  if (self->overrideA >= 0) {
    return self->overrideB;
  }
  int idx = self->tableIndex;
  return *(int *)((char *)((idx << 6) + (int)DAT_0034a7e4) + 0x24);
}
