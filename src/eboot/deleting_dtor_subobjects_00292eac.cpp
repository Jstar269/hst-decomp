/* HSTMATCH module=EBOOT.BIN start=0x00292eac end=0x00292fa0 symbol=FUN_00292eac lang=c++ */
/* Ghidra pseudocode (hstgen.py tag a7) corrected by hand: declared loop counter before walking pointer to fix s2/s3 register allocation; readability pass; exact match verified; names and types await human review. */

#include "hst/types.h"
#include "hst/slot_list_obj.h"

extern "C" {
extern char DAT_00309dcc;
extern char DAT_00309ddc;
extern void FUN_00000a00(void *);
extern int FUN_0005ba00(int, int);
}

struct VC_0 { virtual ~VC_0(); };
struct VC_1 { virtual ~VC_1(); };

/* Deleting destructor: sets the vtable, deletes the owned sub-objects and the seven slots, frees the object when flag > 0. */
extern "C" SlotListObj * FUN_00292eac(SlotListObj *self, short flag)
{
  int i;
  u32 *cur; /* walks the object one word per slot; the slot table starts at word 6 */
  void *owned;
  int obj4;
  
  if (self != (SlotListObj *)0x0) {
    self->vtable = (unsigned int)(&DAT_00309dcc);
    if (self != (SlotListObj *)0x0) {
      self->vtable = (unsigned int)(&DAT_00309ddc);
      owned = self->ownedA;
      if (owned != (void *)0x0) {
        delete ((VC_0 *)(owned));
        self->ownedA = 0;
      }
      obj4 = (int)self->ownedB;
      if (obj4 != 0) {
        FUN_0005ba00(obj4, 1);
        self->ownedB = 0;
      }
      i = 0;
      cur = (u32 *)self;
      do {
        owned = (void *)cur[6];
        if (owned != (void *)0x0) {
          delete ((VC_1 *)(owned));
          cur[6] = 0;
        }
        i = i + 1;
        cur = cur + 1;
      } while (i < SLOT_LIST_COUNT);
    }
    if (0 < flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
