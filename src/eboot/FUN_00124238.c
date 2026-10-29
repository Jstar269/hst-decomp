/* HSTMATCH module=EBOOT.BIN start=0x00124238 end=0x00124268 symbol=FUN_00124238 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct BlendState {
  char pad0[0x68];
  u32 unk68; /* 0x68 */
} BlendState;

extern void FUN_001240fc();

void FUN_00124238(BlendState *self)
{
  FUN_001240fc(self,1,0);
  self->unk68 = 0;
}
