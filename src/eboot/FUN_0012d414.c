/* HSTMATCH module=EBOOT.BIN start=0x0012d414 end=0x0012d454 symbol=FUN_0012d414 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

/* Two helper-handled words of the object (only these are touched here). */
typedef struct PairHolder {
  char pad00[4];
  u32 first;            /* 0x04 */
  char pad08[4];
  u32 second;           /* 0x0c */
} PairHolder;

extern void FUN_000550c8();

/* Pass both words to the helper; the second call also gets arg. */
void FUN_0012d414(PairHolder *self,u32 arg)
{
  FUN_000550c8(self->first);
  FUN_000550c8(self->second,arg);
}
