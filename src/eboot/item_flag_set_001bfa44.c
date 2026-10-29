/* HSTMATCH module=EBOOT.BIN start=0x001bfa44 end=0x001bfbe8 symbol=FUN_001bfa44 lang=c99 data=0x002ea004 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. Data: its string literals (1 strings, 0x002ea004-0x002ea010) are defined in place and placed with data= (tools/hstdatapool.py); before, the source named them through address externs. */
#include "hst/types.h"
#include "hst/item_table.h"

extern u8 DAT_002e9fec;
extern u8 DAT_002e9ff4;
extern u8 DAT_002e9ffc;
extern int DAT_0034174c;
extern int FUN_0000d62c(int);
extern int FUN_00014d64(int, void *);
extern int FUN_000650e0(int);
extern int FUN_0006517c(int, int, int);
extern void FUN_001be424(char *);

/* Write `value` into the flag arrays for every item of entry `entry`, picking the array by the item's type name. */
void FUN_001bfa44(ItemTable *table, int entry, char value)
{
  int list;
  int i;
  int item;
  int id;
  char *p;

  list = DAT_0034174c;
  if (list == 0)
    return;
  if (entry < 0)
    return;
  if (!(entry < FUN_000650e0(list)))
    return;
  for (i = 0; i < 4; i++) {
    item = FUN_0006517c(list, entry + 1, i + 1);
    if (item != 0) {
      if (FUN_00014d64(item, &DAT_002e9fec)) {
      id = FUN_0000d62c(item + 5);
      if (id >= 0 && id < ITEM_FLAG_COUNT)
        p = (char *)&table->flag_a[id];
      else
        p = 0;
      if (p != 0)
        *p = value;
    } else if (FUN_00014d64(item, &DAT_002e9ff4)) {
      id = FUN_0000d62c(item + 5);
      if (id >= 0 && id < ITEM_FLAG_COUNT)
        p = (char *)&table->flag_b[id];
      else
        p = 0;
      if (p != 0)
        *p = value;
    } else if (FUN_00014d64(item, &DAT_002e9ffc)) {
      id = FUN_0000d62c(item + 5);
      if (id >= 0 && id < ITEM_FLAG_COUNT)
        p = (char *)&table->flag_c[id];
      else
        p = 0;
      if (p != 0)
        *p = value;
      }
    } else {
      FUN_001be424("ItemIsNull\n");
    }
  }
}
