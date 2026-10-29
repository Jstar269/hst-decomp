/* HSTMATCH module=EBOOT.BIN start=0x00281128 end=0x00281238 symbol=FUN_00281128 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag a2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_block.h"
#include "hst/entry_records.h"

extern SetupData * DAT_003415a8;
extern u32 * FUN_000149a8();
extern void FUN_0008d148();
extern u32 * FUN_0008d388();
extern int FUN_000d7e30();
extern u64 FUN_001bc630(float param_1);
extern u16 * FUN_00259a1c();
extern void FUN_00281238();

/* Resets the slot block, gives every slot a blank info record and fills slot 0's record from the setup data. */
void FUN_00281128(SlotBlockOwner *self)
{
  float scale;
  u64 packed;
  Rec200 blank0;
  Rec200 blank1;
  Rec200 blank2;
  
  FUN_00281238(&self->block);
  FUN_0008d148(self->unk890);
  FUN_0008d388(&blank0,0,0,0,0,0,0);
  FUN_00259a1c(&self->block.slots[0].id,&blank0);
  FUN_000d7e30(&blank0,-1);
  FUN_0008d388(&blank1,0,0,0,0,0,0);
  FUN_00259a1c(&self->block.slots[1].id,&blank1);
  FUN_000d7e30(&blank1,-1);
  FUN_0008d388(&blank2,0,0,0,0,0,0);
  FUN_00259a1c(&self->block.slots[2].id,&blank2);
  FUN_000d7e30(&blank2,-1);
  FUN_000149a8(self->block.slots[0].rec.name,DAT_003415a8->unk20);
  scale = DAT_003415a8->unk1414;
  packed = FUN_001bc630(scale);
  self->block.slots[0].rec.unk38 = (char)packed;
  self->block.slots[0].rec.unk34 = scale;
}
