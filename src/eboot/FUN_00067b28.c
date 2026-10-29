/* HSTMATCH module=EBOOT.BIN start=0x00067b28 end=0x00067b40 symbol=FUN_00067b28 lang=c99 */
/* Clone of src/eboot/FUN_0014f314.c (hstclone.py tag c1): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/list_head.h"

/* Initialise an empty list: no elements, sentinel linked to itself. */
DListHead * FUN_00067b28(DListHead *list)
{
  list->size = 0;
  list->sentinel.next = &list->sentinel;
  list->sentinel.prev = &list->sentinel;
  return list;
}
