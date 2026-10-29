/* HSTMATCH module=EBOOT.BIN start=0x00102ea4 end=0x00102fb0 symbol=FUN_00102ea4 lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a5) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/node_item.h"

extern "C" {
extern u8 DAT_00307b18;
extern void FUN_00000a00(...);
extern int * FUN_00054600(...);
extern int * FUN_000c3fd8(...);
extern void FUN_00102fb0(...);
extern int * FUN_001073f0(...);
extern int * FUN_001074ac(...);
}
struct VirtualDtorObj { virtual ~VirtualDtorObj(); };

/* Deleting destructor: tear down the owned helper and the embedded members, free self when flags > 0. */
extern "C" NodeItem * FUN_00102ea4(NodeItem *self,short flags)
{
  VirtualDtorObj *owned;
  u32 *member;

  if (self != (NodeItem *)0x0) {
    self->vtable = &DAT_00307b18;
    FUN_00102fb0();
    owned = (VirtualDtorObj *)self->unk1c;
    if (owned != (VirtualDtorObj *)0x0) {
      delete owned;
      self->unk1c = 0;
    }
    member = &self->unk40;
    if ((member != (u32 *)0x0) && (member != (u32 *)0x0)) {
      FUN_000c3fd8(member,0);
    }
    member = &self->unk34;
    if ((member != (u32 *)0x0) && (member != (u32 *)0x0)) {
      FUN_00054600(member,0);
    }
    member = &self->unk28;
    if ((member != (u32 *)0x0) && (member != (u32 *)0x0)) {
      FUN_001074ac(member,0);
    }
    member = &self->unk10;
    if ((member != (u32 *)0x0) && (member != (u32 *)0x0)) {
      FUN_001073f0(member,0);
    }
    member = &self->unk04;
    if ((member != (u32 *)0x0) && (member != (u32 *)0x0)) {
      FUN_001073f0(member,0);
    }
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
