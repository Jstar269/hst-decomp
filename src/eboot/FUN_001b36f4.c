/* HSTMATCH module=EBOOT.BIN start=0x001b36f4 end=0x001b37f4 symbol=FUN_001b36f4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag not recorded in lane candidate inputs/generated/FUN_001b36f4.c) corrected by hand: reused the range-check result as an int and reordered the loop counter declaration; readability pass; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/slot_table.h"

extern int DAT_002e593c[];
extern int DAT_002e5950[];
extern int FUN_00062418();

#define RELEASE_LIST_A_LEN 8
#define RELEASE_LIST_B_LEN 5

/* Delete every slot object listed in the two slot-id tables and clear its slot. */
void FUN_001b36f4(SlotTable **ref)
{
  int slot_id;
  SlotTable *table;
  int i;
  const int *ids;
  void **entry;
  int valid;
  void *obj;

  table = *ref;
  i = 0;
  ids = DAT_002e5950;
  do {
    slot_id = *ids;
    valid = slot_id < SLOT_COUNT;
    if (valid) {
      valid = table->slot[slot_id] != 0;
    }
    if (valid) {
      entry = &table->slot[slot_id];
      obj = *entry;
      if (obj != 0) {
        FUN_00062418(obj,1);
        *entry = 0;
      }
    }
    i = i + 1;
    ids = ids + 1;
  } while (i < RELEASE_LIST_A_LEN);
  i = 0;
  ids = DAT_002e593c;
  do {
    slot_id = *ids;
    valid = slot_id < SLOT_COUNT;
    if (valid) {
      valid = table->slot[slot_id] != 0;
    }
    if (valid) {
      entry = &table->slot[slot_id];
      obj = *entry;
      if (obj != 0) {
        FUN_00062418(obj,1);
        *entry = 0;
      }
    }
    i = i + 1;
    ids = ids + 1;
  } while (i < RELEASE_LIST_B_LEN);
}
