/* HSTMATCH module=EBOOT.BIN start=0x0019b460 end=0x0019b490 symbol=FUN_0019b460 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct ClearedObj {
  char pad0[0x130];
  u32 unk130; /* 0x130 */
  u32 unk134; /* 0x134 */
  u32 unk138; /* 0x138 */
} ClearedObj;

extern void FUN_0010b5a4();

/* Runs the helper, then clears three words. */
void FUN_0019b460(ClearedObj *self)
{
  FUN_0010b5a4();
  self->unk138 = 0;
  self->unk130 = 0;
  self->unk134 = 0;
}
