/* HSTMATCH module=EBOOT.BIN start=0x002b56ec end=0x002b5778 symbol=FUN_002b56ec lang=c99 */
/* Mechanical translation of Ghidra pseudocode (hstgen.py tag t0), refined by hstperm.py random mutation from try/gen-s256b/v0c/FUN_002b56ec.c; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_00309fd4;
extern u32 DAT_0034b5dc;
extern void FUN_00000788();
extern void FUN_00000a00();
extern u32 * FUN_0001f0f0();
extern u32 * FUN_000510c0();
extern void FUN_0005aeac();

#define ITEM_COUNT 0x14   /* elements in the item array */
#define ITEM_STRIDE 0x70  /* bytes per element */

typedef struct ItemArrayObj {
  u32 vtable;                              /* 0x00 */
  char pad04[0x3c];
  char sub[0x50];                          /* 0x40 embedded sub-object */
  char items[ITEM_COUNT][ITEM_STRIDE];     /* 0x90 */
} ItemArrayObj;

/* Deleting destructor: reset the global, destroy the item array and sub-object, run the base teardown, free when flag > 0. */
ItemArrayObj * FUN_002b56ec(ItemArrayObj *self,short flag)
{
  if (self != (ItemArrayObj *)0x0) {
    self->vtable = (unsigned int)(&DAT_00309fd4);
    DAT_0034b5dc = 0;
    FUN_00000788(self->items,FUN_0005aeac,ITEM_STRIDE,ITEM_COUNT);
    FUN_000510c0(self->sub,0xffffffff);
    FUN_0001f0f0(self,0);
    if (flag > 0) {
      FUN_00000a00(self);
    }
  }
  return self;
}
