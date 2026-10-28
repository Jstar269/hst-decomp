/* HSTMATCH module=EBOOT.BIN start=0x002890c0 end=0x00289110 symbol=FUN_002890c0 lang=c99 */
/* Hand-written reconstruction from the disassembly; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0034179c;
extern int FUN_001b1f7c(void *, int);

typedef struct Obj { char pad[0x4c]; int idx; } Obj;

int FUN_002890c0(Obj *o)
{
  if (o->idx >= 0) {
    if (FUN_001b1f7c(&DAT_0034179c, o->idx) == 0) {
      o->idx = -1;
    }
  }
  return o->idx >= 0;
}
