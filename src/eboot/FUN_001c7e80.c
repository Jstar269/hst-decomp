/* HSTMATCH module=EBOOT.BIN start=0x001c7e80 end=0x001c7e8c symbol=FUN_001c7e80 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct PairHolder {
  char pad00[0x14c];
  u32 unk14c; /* 0x14c */
  u32 unk150; /* 0x150 */
} PairHolder;

/* Stores two words. */
void FUN_001c7e80(PairHolder *self,u32 a,u32 b)
{
  self->unk14c = a;
  self->unk150 = b;
}
