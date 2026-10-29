/* HSTMATCH module=EBOOT.BIN start=0x001b2ee0 end=0x001b2f60 symbol=FUN_001b2ee0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. matching idiom: three if (p != 0) { if (p != 0) { free(p,1); p-field = 0; } } blocks reproduce retail's duplicated null guard and beqzl+beqz chain. */
#include "hst/types.h"
#include "hst/slot_table.h"

extern int FUN_00062418();

/* Release the objects held in slots 0x3f, 0x3e and 0xac. */
void FUN_001b2ee0(SlotTable **ref)
{
  void *obj;
  SlotTable *table;

  table = *ref;
  obj = table->slot[0x3f];
  if (obj != 0) {
    if (obj != 0) {
      FUN_00062418(obj,1);
      table->slot[0x3f] = 0;
    }
  }
  obj = table->slot[0x3e];
  if (obj != 0) {
    if (obj != 0) {
      FUN_00062418(obj,1);
      table->slot[0x3e] = 0;
    }
  }
  obj = table->slot[0xac];
  if (obj != 0) {
    if (obj != 0) {
      FUN_00062418(obj,1);
      table->slot[0xac] = 0;
    }
  }
}
