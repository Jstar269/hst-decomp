/* HSTMATCH module=EBOOT.BIN start=0x0027d17c end=0x0027d34c symbol=FUN_0027d17c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s27d17c) corrected by hand: the null arm stores the pointer value
   instead of 0 (`self->sub = offset; sub = offset;`), which keeps the zero already live in v0 so
   MWCC needs no `move v0,zero` and can share the store in the beqzl delay slot; the two loop
   counters are declared (count) before (offset); readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/entry_pool.h"

extern u8 DAT_00309c60;
extern EntryPoolObj *DAT_0034a7e0;
extern u8 * DAT_0034a7e4;
extern int FUN_00000a90();
extern int FUN_00000bcc();
extern u32 * FUN_0001f06c();
extern void FUN_0001f1fc();
extern void FUN_0001f21c();
extern u32 * FUN_0027b8cc();

/* Constructor: register as the global instance, allocate the entry pool and clear it (each entry ends with 1 in its last word), build the sub-object. */
EntryPoolObj * FUN_0027d17c(EntryPoolObj *self)
{
  int count;
  u32 sub;
  int offset;   /* byte offset of the entry being cleared, then reused for the sub-object allocation */
  
  FUN_0001f06c();
  self->vtable = &DAT_00309c60;
  self->sub = 0;
  DAT_0034a7e0 = self;
  DAT_0034a7e4 = (u8 *)(FUN_00000a90(0x2000));
  count = 0;
  offset = 0;
  do {
    count = count + 1;
    *(u32 *)(DAT_0034a7e4 + offset) = 0;
    *(u32 *)(DAT_0034a7e4 + offset + 4) = 0;
    *(u32 *)(DAT_0034a7e4 + offset + 8) = 0;
    *(u32 *)(DAT_0034a7e4 + offset + 0xc) = 0;
    *(u32 *)(DAT_0034a7e4 + offset + 0x10) = 0;
    *(u32 *)(DAT_0034a7e4 + offset + 0x14) = 0;
    *(u32 *)(DAT_0034a7e4 + offset + 0x18) = 0;
    *(u32 *)(DAT_0034a7e4 + offset + 0x1c) = 0;
    *(u32 *)(DAT_0034a7e4 + offset + 0x20) = 0;
    *(u32 *)(DAT_0034a7e4 + offset + 0x24) = 0;
    *(u32 *)(DAT_0034a7e4 + offset + 0x28) = 0;
    *(u32 *)(DAT_0034a7e4 + offset + 0x2c) = 0;
    *(u32 *)(DAT_0034a7e4 + offset + 0x30) = 0;
    *(u32 *)(DAT_0034a7e4 + offset + 0x34) = 0;
    *(u32 *)(DAT_0034a7e4 + offset + 0x38) = 0;
    *(u32 *)(DAT_0034a7e4 + offset + 0x3c) = 1;
    offset = offset + 0x40;
  } while (count < ENTRY_POOL_SLOTS);
  self->unk40 = 0;
  self->unk44 = 0;
  offset = FUN_00000bcc(0x80);
  if (offset != 0) {
    sub = (unsigned int)(FUN_0027b8cc(offset));
    self->sub = (void *)sub;
  }
  else {
    sub = (unsigned int)(offset);
    self->sub = (void *)offset;
  }
  FUN_0001f21c(self,sub);
  FUN_0001f1fc(self->sub,0);
  return self;
}
