/* HSTMATCH module=hstp_trans_main.prx start=0x0029c6a8 end=0x0029c74c symbol=FUN_0029c6a8 lang=c99 */
/* Clone of src/eboot/FUN_0028aeb4.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/vec_triple.h"

extern void FUN_00000a00();
extern void FUN_0029cde8();
extern void * FUN_0029dec0();
extern void * FUN_0029df7c();
extern void * FUN_0029e038();

/* Deleting destructor: tears down the three arrays in reverse order. */
VecTriple * FUN_0029c6a8(VecTriple *obj,short flags)
{
  RawVec *array;
  
  if (obj != (VecTriple *)0x0) {
    FUN_0029cde8();
    array = &obj->third;
    if ((array != (RawVec *)0x0) && (array != (RawVec *)0x0)) {
      FUN_0029e038(array,0);
    }
    array = &obj->second;
    if ((array != (RawVec *)0x0) && (array != (RawVec *)0x0)) {
      FUN_0029df7c(array,0);
    }
    if ((obj != (VecTriple *)0x0) && (obj != (VecTriple *)0x0)) {
      FUN_0029dec0(obj,0);
    }
    if (0 < flags) {
      FUN_00000a00(obj);
    }
  }
  return obj;
}
