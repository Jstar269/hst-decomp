/* HSTMATCH module=EBOOT.BIN start=0x00092c38 end=0x00092d10 symbol=FUN_00092c38 lang=c++ */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/char_model.h"

extern "C" {
extern u32 * FUN_0005d818(...);
extern void FUN_00092258(...);
}
struct VC_0 { virtual ~VC_0(); };

/* Deletes the model item in the given slot, clears the extra state tied to slots 0, 2 and 5,
   then refreshes the flags (FUN_00092258). Does nothing if the slot is empty. */
extern "C" void FUN_00092c38(CharModel *self,int slot)
{
  ModelItem *old_item;
  u32 count;
  ModelItem **slot_ptr;
  int addr;
  
  old_item = self->item[slot];
  slot_ptr = &self->item[slot];
  if (old_item != (ModelItem *)0x0) {
    if (old_item != (ModelItem *)0x0) {
      delete ((VC_0 *)(old_item));
      *slot_ptr = 0;
    }
    if ((slot == 0) && (self->unk70 != 0)) {
      FUN_0005d818(self->unk70,1);
      self->unk70 = 0;
    }
    if (slot == 2) {
      count = 0;
      addr = (int)self;
      do {
        count = count + 1;
        *(u32 *)(addr + 4) = 0xffffffff;
        addr = addr + 4;
      } while (count < 7);
    }
    if (slot == 5) {
      self->unk20 = CHAR_INDEX_NONE;
    }
    FUN_00092258(self);
  }
}
