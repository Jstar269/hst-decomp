/* HSTMATCH module=EBOOT.BIN start=0x001936f0 end=0x00193758 symbol=FUN_001936f0 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s128a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/tree_map.h"

extern void FUN_00000a00();
extern int FUN_001965b0();

/* Destructor of a name map: clears the tree, then frees the object when flags > 0. */
TreeMap * FUN_001936f0(TreeMap *self,short flags)
{
  if (self != 0) {
    if (((self != 0) && (self != 0)) && (self != 0)) {
      FUN_001965b0(self,0);
    }
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
