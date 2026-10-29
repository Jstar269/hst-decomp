/* HSTMATCH module=EBOOT.BIN start=0x001c6aa0 end=0x001c6b38 symbol=FUN_001c6aa0 lang=c99 helpers=FUN_001c5018@0x001c5018-0x001c5044 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/gimmick_mgr.h"

extern char DAT_002ea6d0[];
extern void FUN_001c67e8(GimmickMgr *mgr, MgrItem *item);

static void FUN_001c5018(...)
{
}

/* Registers item at slot index (when the index is in range): adds it to the manager, warns if the slot is taken, then stores it. */
void FUN_001c6aa0(GimmickMgr *mgr, unsigned int index, int value, MgrItem *item)
{
  FUN_001c67e8(mgr, item);
  if (index < mgr->slot_count) {
    if (mgr->slots[index] != 0) {
      FUN_001c5018(DAT_002ea6d0, index);
    }
    item->index = index;
    item->unk34 = value;
    mgr->slots[index] = item;
  }
}
