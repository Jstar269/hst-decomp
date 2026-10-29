/* HSTMATCH module=hstp_trans_main.prx start=0x001087a8 end=0x001088b4 symbol=FUN_001087a8 lang=c++ */
/* Clone of src/eboot/FUN_00102ea4.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/node_item.h"

extern "C" {
extern u8 DAT_003b0de4;
extern void FUN_00000a00(...);
extern int * FUN_0005514c(...);
extern int * FUN_000c7840(...);
extern void FUN_001088b4(...);
extern int * FUN_0010d1b0(...);
extern int * FUN_0010d26c(...);
}
struct VirtualDtorObj { virtual ~VirtualDtorObj(); };

/* Deleting destructor: tear down the owned helper and the embedded members, free self when flags > 0. */
extern "C" NodeItem * FUN_001087a8(NodeItem *self,short flags)
{
  VirtualDtorObj *owned;
  u32 *member;

  if (self != (NodeItem *)0x0) {
    self->vtable = &DAT_003b0de4;
    FUN_001088b4();
    owned = (VirtualDtorObj *)self->unk1c;
    if (owned != (VirtualDtorObj *)0x0) {
      delete owned;
      self->unk1c = 0;
    }
    member = &self->unk40;
    if ((member != (u32 *)0x0) && (member != (u32 *)0x0)) {
      FUN_000c7840(member,0);
    }
    member = &self->unk34;
    if ((member != (u32 *)0x0) && (member != (u32 *)0x0)) {
      FUN_0005514c(member,0);
    }
    member = &self->unk28;
    if ((member != (u32 *)0x0) && (member != (u32 *)0x0)) {
      FUN_0010d26c(member,0);
    }
    member = &self->unk10;
    if ((member != (u32 *)0x0) && (member != (u32 *)0x0)) {
      FUN_0010d1b0(member,0);
    }
    member = &self->unk04;
    if ((member != (u32 *)0x0) && (member != (u32 *)0x0)) {
      FUN_0010d1b0(member,0);
    }
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
