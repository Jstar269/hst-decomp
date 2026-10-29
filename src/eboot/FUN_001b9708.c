/* HSTMATCH module=EBOOT.BIN start=0x001b9708 end=0x001b9720 symbol=FUN_001b9708 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/list_head.h"

/* Initialise an empty doubly linked list: size 0, sentinel linked to itself. */
DListHead * FUN_001b9708(DListHead *list)
{
  list->size = 0;
  list->sentinel.next = &list->sentinel;
  list->sentinel.prev = &list->sentinel;
  return list;
}
