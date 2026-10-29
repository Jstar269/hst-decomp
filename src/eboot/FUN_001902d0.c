/* HSTMATCH module=EBOOT.BIN start=0x001902d0 end=0x00190304 symbol=FUN_001902d0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct BlockVec {
  char head[0xc];
  u32 unkc;  /* 0xc */
  u32 unk10; /* 0x10 */
  u32 unk14; /* 0x14 */
} BlockVec;

extern u32 FUN_000031f0();

/* Constructor: base setup, then clears the three trailing words. */
BlockVec * FUN_001902d0(BlockVec *self)
{
  FUN_000031f0();
  self->unkc = 0;
  self->unk10 = 0;
  self->unk14 = 0;
  return self;
}
