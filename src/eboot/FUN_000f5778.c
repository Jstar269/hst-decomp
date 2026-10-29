/* HSTMATCH module=EBOOT.BIN start=0x000f5778 end=0x000f57a4 symbol=FUN_000f5778 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct FlaggedObj {
  char pad0[0x54];
  u8 unk54; /* 0x54 cleared after the base setup call */
} FlaggedObj;

extern void FUN_00103628();

void FUN_000f5778(FlaggedObj *self)
{
  FUN_00103628(self,0);
  self->unk54 = 0;
}
