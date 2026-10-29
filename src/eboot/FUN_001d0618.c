/* HSTMATCH module=EBOOT.BIN start=0x001d0618 end=0x001d0624 symbol=FUN_001d0618 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct Owner58 {
  char pad0[0x58];
  void *unk58; /* 0x58 */
} Owner58;

extern void FUN_0010b8cc();

void FUN_001d0618(Owner58 *self,u32 arg)
{
  FUN_0010b8cc(self->unk58,arg,0);
}
