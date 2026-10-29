/* HSTMATCH module=EBOOT.BIN start=0x00192fb8 end=0x00192fd0 symbol=FUN_00192fb8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/list_head.h"

/* Initialise an empty list: no elements, sentinel linked to itself. */
DListHead * FUN_00192fb8(DListHead *list)
{
  list->size = 0;
  list->sentinel.next = &list->sentinel;
  list->sentinel.prev = &list->sentinel;
  return list;
}
