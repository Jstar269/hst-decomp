/* HSTMATCH module=EBOOT.BIN start=0x001925a0 end=0x001925f0 symbol=FUN_001925a0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

/* Four-word record. */
typedef struct Words4 {
  u32 w[4];
} Words4;

/* Swaps the contents of two records word by word (no-op when they are the same record). */
void FUN_001925a0(Words4 *a,Words4 *b)
{
  u32 tmp;
  
  if (a != b) {
    tmp = a->w[0];
    a->w[0] = b->w[0];
    b->w[0] = tmp;
    tmp = a->w[1];
    a->w[1] = b->w[1];
    b->w[1] = tmp;
    tmp = a->w[2];
    a->w[2] = b->w[2];
    b->w[2] = tmp;
    tmp = a->w[3];
    a->w[3] = b->w[3];
    b->w[3] = tmp;
  }
}
