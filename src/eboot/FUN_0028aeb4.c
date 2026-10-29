/* HSTMATCH module=EBOOT.BIN start=0x0028aeb4 end=0x0028af58 symbol=FUN_0028aeb4 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/vec_triple.h"

extern void FUN_00000a00();
extern void FUN_0028b5f4();
extern void * FUN_0028c6f8();
extern void * FUN_0028c7b4();
extern void * FUN_0028c870();

/* Deleting destructor: tears down the three arrays in reverse order. */
VecTriple * FUN_0028aeb4(VecTriple *obj,short flags)
{
  RawVec *array;
  
  if (obj != (VecTriple *)0x0) {
    FUN_0028b5f4();
    array = &obj->third;
    if ((array != (RawVec *)0x0) && (array != (RawVec *)0x0)) {
      FUN_0028c870(array,0);
    }
    array = &obj->second;
    if ((array != (RawVec *)0x0) && (array != (RawVec *)0x0)) {
      FUN_0028c7b4(array,0);
    }
    if ((obj != (VecTriple *)0x0) && (obj != (VecTriple *)0x0)) {
      FUN_0028c6f8(obj,0);
    }
    if (0 < flags) {
      FUN_00000a00(obj);
    }
  }
  return obj;
}
