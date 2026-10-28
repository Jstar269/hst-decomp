/* HSTMATCH module=hstp_trans_main.prx start=0x000b6770 end=0x000b67dc symbol=FUN_000b6770 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

u32 FUN_000b6770(int param_1)
{
  int *owner = *(int **)(param_1 + 0x5bc);
  int *p = *(int **)((char *)owner + 0x58);
  int id = p != 0 ? *(int *)((char *)p + 0xf0) : -1;
  if (id < 0x44) goto special;
  if (id < 0x88) return 1;
special:
  switch (id) {
    case 0x98:
    case 0x9a:
    case 0x9c:
      return 1;
    default:
      return 0;
  }
}
