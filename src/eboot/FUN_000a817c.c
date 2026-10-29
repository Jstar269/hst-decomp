/* HSTMATCH module=EBOOT.BIN start=0x000a817c end=0x000a81b4 symbol=FUN_000a817c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag probe2) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

/* Object with two words at 0x144 and 0x148 handed to a helper. */
typedef struct PairObj {
  char pad00[0x144];
  u32 unk144;               /* 0x144 */
  u32 unk148;               /* 0x148 */
} PairObj;

extern u32 DAT_00338b44;
extern void FUN_000dc820();
extern void FUN_000dc90c();

/* Passes the two words to the helper for the global handle, then calls the second helper on it. */
void FUN_000a817c(PairObj *self)
{
  FUN_000dc90c(DAT_00338b44,self->unk144,self->unk148);
  FUN_000dc820(DAT_00338b44);
}
