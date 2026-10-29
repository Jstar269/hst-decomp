/* HSTMATCH module=hstp_trans_main.prx start=0x0012f40c end=0x0012f43c symbol=FUN_0012f40c lang=c99 */
/* Clone of src/eboot/FUN_00124238.c (hstclone.py tag x14): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct BlendState {
  char pad0[0x68];
  u32 unk68; /* 0x68 */
} BlendState;

extern void FUN_0012f2d0();

void FUN_0012f40c(BlendState *self)
{
  FUN_0012f2d0(self,1,0);
  self->unk68 = 0;
}
