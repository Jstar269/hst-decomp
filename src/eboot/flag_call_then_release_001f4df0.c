/* HSTMATCH module=EBOOT.BIN start=0x001f4df0 end=0x001f4e40 symbol=FUN_001f4df0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_group.h"

extern u8 DAT_0034179c;
extern UiHost *DAT_003386b0;
extern void FUN_001b3ce8(void *, int);
extern u32 FUN_001b4e14(void *, int, int, int, int);

void FUN_001f4df0(SlotGroup *self)
{
  HostSub *sub = DAT_003386b0->sub;
  if (self->flag != 0) {
    FUN_001b4e14(sub->widget,0xbc,0,0,0);
  }
  FUN_001b3ce8(&DAT_0034179c,0x27);
}
