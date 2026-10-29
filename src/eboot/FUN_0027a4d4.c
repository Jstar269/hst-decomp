/* HSTMATCH module=EBOOT.BIN start=0x0027a4d4 end=0x0027a4ec symbol=FUN_0027a4d4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/list_head.h"

/* Initialises an empty doubly linked list: no elements, sentinel linked to itself. */
DListHead * FUN_0027a4d4(DListHead *list)
{
  list->size = 0;
  list->sentinel.next = &list->sentinel;
  list->sentinel.prev = &list->sentinel;
  return list;
}
