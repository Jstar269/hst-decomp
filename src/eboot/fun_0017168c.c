/* HSTMATCH module=EBOOT.BIN start=0x0017168c end=0x00171714 symbol=FUN_0017168c lang=c99 */
/* Hand-written reconstruction from the disassembly (started from hstgen.py tag a1/v0); matching idiom: reuse total for total < 5 so MWCC branches on the comparison result register; exact match verified; names and types await human review. */
#include "hst/types.h"

extern void FUN_001b1f84(void *, int *);
extern u32 FUN_001b2bb8();
extern u8 DAT_0034179c;

struct Self {
  char pad0[0x588];
  int x588;
  int x58c;
  int x590;
  int x594;
  int x598;
  char pad1[0x98];
  int handle;       /* 0x634 handle returned by the global object helper, negative when none */
};

void FUN_0017168c(struct Self *self)
{
  u32 new_handle;

  int total = 0;
  total += self->x588;
  total += self->x58c;
  total += self->x590;
  total += self->x594;
  total += self->x598;
  if ((total = (total < 5))) {
  }
  else {
    if (self->handle >= 0) {
      FUN_001b1f84(&DAT_0034179c,&self->handle);
    }
    new_handle = FUN_001b2bb8(&DAT_0034179c,0x58);
    self->handle = new_handle;
  }
}
