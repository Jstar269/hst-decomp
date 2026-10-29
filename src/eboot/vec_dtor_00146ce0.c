/* HSTMATCH module=EBOOT.BIN start=0x00146ce0 end=0x00146d44 symbol=FUN_00146ce0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag gen-a1/v0) corrected by hand: the delete call (0xa00) takes *param_1 as argument (Ghidra dropped it); readability pass; exact match verified; names and types await human review. */
#include "hst/vec_reserve.h"

extern void FUN_00000a00(void *);
extern void FUN_00146d44();

/* Deleting destructor of a vector: destroys the elements, frees the block, frees self when flag > 0. */
RawVec * FUN_00146ce0(RawVec *vec,short flag)
{
  if (vec != (RawVec *)0x0) {
    FUN_00146d44(vec,vec->size);
    if (vec->data != 0) {
      FUN_00000a00(vec->data);
    }
    if (0 < flag) {
      FUN_00000a00(vec);
    }
  }
  return vec;
}
