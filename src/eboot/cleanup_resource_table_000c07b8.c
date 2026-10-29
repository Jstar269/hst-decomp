/* HSTMATCH module=EBOOT.BIN start=0x000c07b8 end=0x000c092c symbol=FUN_000c07b8 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Matching idiom: pass each tested field pointer to FUN_000009e4; the entry is indexed by the plain loop index with strength reduction off. */
#include "hst/types.h"
#include "hst/data_pack.h"

extern char DAT_00307408;
extern unsigned char DAT_00338acc;
extern void FUN_000009e4(void *);
extern void FUN_00000a00(void *);
extern u32 * FUN_0001f0f0(void *, int);
extern void FUN_000c1aa0(void *, int);

#pragma opt_strength_reduction off

/* Destructor: frees each entry's payload (data or owned), the two work tables and both arrays. */
DataPack * FUN_000c07b8(DataPack *self,short delete_flag)
{
  void *table;
  u32 index;
  
  if (self != (DataPack *)0x0) {
    self->vtable = &DAT_00307408;
    DAT_00338acc = 0;
    index = 0;
    if (self->entries.size != 0) {
      do {
        void *owned = self->entries.data[index].owned;
        if (owned != 0) {
          if (owned != 0) {
            FUN_000009e4(owned);
            self->entries.data[index].owned = 0;
          }
        } else {
          void *data = self->entries.data[index].data;
          if (data != 0) {
            if (data != 0) {
              FUN_000009e4(data);
              self->entries.data[index].data = 0;
            }
          }
        }
        index = index + 1;
      } while (index < self->entries.size);
    }
    if (self->table72c != 0) {
      if (self->table72c != 0) {
        FUN_000009e4(self->table72c);
        self->table72c = 0;
      }
    }
    table = self->table76c;
    if ((table != 0) && (table != 0)) {
      FUN_000009e4(table);
      self->table76c = 0;
    }
    if ((&self->items) != (PackItemVec *)0x0 && (&self->items) != (PackItemVec *)0x0) {
      FUN_000c1aa0(&self->items,0);
    }
    if ((&self->entries) != (DataEntryVec *)0x0 && (&self->entries) != (DataEntryVec *)0x0) {
      FUN_000c1aa0(&self->entries,0);
    }
    FUN_0001f0f0(self,0);
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
