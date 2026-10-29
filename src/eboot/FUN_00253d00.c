/* HSTMATCH module=EBOOT.BIN start=0x00253d00 end=0x00253d30 symbol=FUN_00253d00 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s64a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

/* Object with two words after its base part. */
typedef struct DerivedObj {
  char pad0[0x10];
  u32 unk10;                    /* 0x10 */
  u32 unk14;                    /* 0x14 */
} DerivedObj;

extern u32 * FUN_00253d30(DerivedObj *);

/* Constructor: runs the base constructor, then clears the two words. */
DerivedObj * FUN_00253d00(DerivedObj *self)
{
  FUN_00253d30(self);
  self->unk10 = 0;
  self->unk14 = 0;
  return self;
}
