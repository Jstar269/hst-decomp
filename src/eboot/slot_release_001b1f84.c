/* HSTMATCH module=EBOOT.BIN start=0x001b1f84 end=0x001b2040 symbol=FUN_001b1f84 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
/* Earlier near miss wip/slot_release_001b1f84.c (registers only) fixed by the inline early-return HasSlot() form with the identical-layout SlotViewAlias for the reload, see release_slot_handle_001b4848.c. */
#include "hst/slot_table.h"

#define VIEW_WORDS 0x1eb /* words before the two fields (SlotTable.unk7ac / unk7b0) */

/* The slot table as an int array up to its current handle and slot index. */
typedef struct SlotView { int slots[VIEW_WORDS]; int cur_handle; int slot_index; } SlotView;
typedef struct SlotViewAlias { int slots[VIEW_WORDS]; int cur_handle; int slot_index; } SlotViewAlias;

extern void FUN_00062904();
extern void FUN_000629cc();
extern int FUN_001b2438();

static inline int HasSlot(SlotView *o)
{
  int ok = o->slot_index < SLOT_COUNT;
  if (!ok) return ok;
  return o->slots[o->slot_index] != 0;
}

/* Release `*handle`: if it is the current handle, stop it on its slot (when that slot exists) and reset the slot index; otherwise just FUN_000629cc. Returns 0 when FUN_001b2438 rejects it. */
int FUN_001b1f84(SlotView **ctx, int *handle)
{
  SlotView *o;
  int cur;

  if (FUN_001b2438(ctx, handle) == 0) {
    return 0;
  }
  o = *ctx;
  cur = o->cur_handle;
  if (*handle == cur) {
    if (HasSlot(o)) {
      if (cur >= 0) {
        FUN_00062904(o->slots[((SlotViewAlias *)o)->slot_index], cur);
        o->cur_handle = -1;
      }
      o->slot_index = SLOT_COUNT;
    }
  } else {
    FUN_000629cc(*handle);
  }
  *handle = -1;
  return 1;
}
