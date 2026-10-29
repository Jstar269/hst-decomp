/* HSTMATCH module=EBOOT.BIN start=0x0019cf80 end=0x0019cf8c symbol=FUN_0019cf80 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

typedef struct ResetTarget {
  char pad00[0xc];
  u32 unkc;     /* 0x0c */
  char pad10[0x42];
  u8 unk52;     /* 0x52 */
} ResetTarget;

/* Clear the word at 0x0c and the byte at 0x52. */
void FUN_0019cf80(ResetTarget *self)
{
  self->unkc = 0;
  self->unk52 = 0;
}
