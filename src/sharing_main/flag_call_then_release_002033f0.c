/* HSTMATCH module=hstp_trans_main.prx start=0x002033f0 end=0x00203440 symbol=FUN_002033f0 lang=c99 */
/* Hand-written reconstruction from the disassembly (port of the matched EBOOT twin src/eboot/flag_call_then_release_001f4df0.c with the Sharing addresses); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_group.h"

extern u8 DAT_003eaad8;
extern UiHost *DAT_003e19f0;
extern void FUN_001c1f44(void *, int);
extern u32 FUN_001c2a28(void *, int, int, int, int);

void FUN_002033f0(SlotGroup *self)
{
  HostSub *sub = DAT_003e19f0->sub;
  if (self->flag != 0) {
    FUN_001c2a28(sub->widget,0xbc,0,0,0);
  }
  FUN_001c1f44(&DAT_003eaad8,0x27);
}
