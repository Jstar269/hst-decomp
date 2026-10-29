/* HSTMATCH module=EBOOT.BIN start=0x001d407c end=0x001d4088 symbol=FUN_001d407c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct PairObj {
  char pad0[0x24];
  u32 unk24;  /* 0x24 */
  u32 unk28;  /* 0x28 */
} PairObj;

/* Store the same value in both fields. */
void FUN_001d407c(PairObj *self,u32 value)
{
  self->unk24 = value;
  self->unk28 = value;
}
