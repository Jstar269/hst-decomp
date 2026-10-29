/* HSTMATCH module=EBOOT.BIN start=0x00192d8c end=0x00192e18 symbol=FUN_00192d8c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag p1), refined by hstperm.py random mutation (perm-p1/r02/f0247_00192d8c_m04.c), corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/pose_holder.h"

extern void FUN_00000a00();
extern void FUN_00192e18();
extern void FUN_00192f18();

/* Deleting destructor: releases the owned objects, erases the element list range and frees the object when delete_flag > 0. */
PoseHolder * FUN_00192d8c(PoseHolder *self,short delete_flag)
{
  DListHead *list;
  u8 iter [4];
  u32 first;
  DListLinks *end;
  
  if (self != 0) {
    FUN_00192e18();
    list = &self->list;
    if (((list != 0) && (list != 0)) && (list != 0)) {
      end = &self->list.sentinel;
      first = (u32)self->list.sentinel.next;
      FUN_00192f18(iter,list,&first,&end);
    }
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
