/* HSTMATCH module=hstp_trans_main.prx start=0x001c73f4 end=0x001c740c symbol=FUN_001c73f4 lang=c99 */
/* Clone of src/eboot/FUN_0014f314.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/list_head.h"

/* Initialise an empty list: no elements, sentinel linked to itself. */
DListHead * FUN_001c73f4(DListHead *list)
{
  list->size = 0;
  list->sentinel.next = &list->sentinel;
  list->sentinel.prev = &list->sentinel;
  return list;
}
