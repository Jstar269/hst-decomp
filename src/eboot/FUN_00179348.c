/* HSTMATCH module=EBOOT.BIN start=0x00179348 end=0x001793e8 symbol=FUN_00179348 lang=c99 rodata=0x002c1f90 */
/* Ghidra pseudocode (hstgen.py tag u1ge) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/list_host.h"

/* First word of the index'th record in the second list family chosen by kind; 0 for kind 0. */
u32 FUN_00179348(ListHost *host,u32 kind,int index)
{
  u32 value;
  
  switch(kind) {
  case 0:
    value = 0;
    break;
  case 1:
    value = *((u32 **)host->list1b.data)[index];
    break;
  case 2:
    value = *((u32 **)host->list2b.data)[index];
    break;
  case 3:
  case 4:
    value = *((u32 **)host->list3.data)[index];
    break;
  case 5:
    value = *((u32 **)host->shared->data)[index];
    break;
  default:
    value = 0;
  }
  return value;
}
