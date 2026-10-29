/* HSTMATCH module=EBOOT.BIN start=0x002291f8 end=0x002292a8 symbol=FUN_002291f8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/tree_map.h"

extern void FUN_00000a00();
extern void FUN_002293d4();
extern void FUN_00229774();
extern int FUN_00229a54();
extern int FUN_00229b94();

/* Destructor of the two-tree map: frees the string keys, then both trees; frees self when delete_flag > 0. */
TreePair *FUN_002291f8(TreePair *self,short delete_flag)
{
  TreeMap *pairs;
  
  if (self != 0) {
    FUN_00229774();
    FUN_002293d4(self);
    pairs = &self->pairs;
    if ((((pairs != 0) && (pairs != 0)) && (pairs != 0)) && (pairs != 0)) {
      FUN_00229b94(pairs,0);
    }
    if (((self != 0) && (self != 0)) && ((self != 0 && (self != 0)))) {
      FUN_00229a54(self,0);
    }
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
