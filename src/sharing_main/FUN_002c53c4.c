/* HSTMATCH module=hstp_trans_main.prx start=0x002c53c4 end=0x002c5450 symbol=FUN_002c53c4 lang=c99 */
/* Clone of src/eboot/FUN_002b56ec.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b32a0;
extern u32 DAT_003f491c;
extern void FUN_00000788();
extern void FUN_00000a00();
extern u32 * FUN_0001ed28();
extern u32 * FUN_000519d4();
extern void FUN_0005bbd8();

#define ITEM_COUNT 0x14   /* elements in the item array */
#define ITEM_STRIDE 0x70  /* bytes per element */

typedef struct ItemArrayObj {
  u32 vtable;                              /* 0x00 */
  char pad04[0x3c];
  char sub[0x50];                          /* 0x40 embedded sub-object */
  char items[ITEM_COUNT][ITEM_STRIDE];     /* 0x90 */
} ItemArrayObj;

/* Deleting destructor: reset the global, destroy the item array and sub-object, run the base teardown, free when flag > 0. */
ItemArrayObj * FUN_002c53c4(ItemArrayObj *self,short flag)
{
  if (self != (ItemArrayObj *)0x0) {
    self->vtable = (unsigned int)(&DAT_003b32a0);
    DAT_003f491c = 0;
    FUN_00000788(self->items,FUN_0005bbd8,ITEM_STRIDE,ITEM_COUNT);
    FUN_000519d4(self->sub,0xffffffff);
    FUN_0001ed28(self,0);
    if (flag > 0) {
      FUN_00000a00(self);
    }
  }
  return self;
}
