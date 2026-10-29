/* HSTMATCH module=EBOOT.BIN start=0x001792b0 end=0x00179348 symbol=FUN_001792b0 lang=c99 rodata=0x002c1f78 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. (jump table in .rodata; case 0 is an empty label so its entry reuses the shared return-0 block) */
#include "hst/list_host.h"

/* First word of the index'th record in the list chosen by kind (kinds 3 and 4 share a list); 0 for kind 0. */
int FUN_001792b0(ListHost *host, int kind, int index)
{
  switch (kind) {
  case 1:
    return *((int **)host->list1a.data)[index];
  case 2:
    return *((int **)host->list2a.data)[index];
  case 3:
  case 4:
    return *((int **)host->list3.data)[index];
  case 5:
    return *((int **)host->shared->data)[index];
  case 0:
    break;
  }
  return 0;
}
