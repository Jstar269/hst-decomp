/* HSTMATCH module=hstp_trans_main.prx start=0x0019f59c end=0x0019f628 symbol=FUN_0019f59c lang=c99 */
/* Clone of src/eboot/FUN_00192d8c.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/pose_holder.h"

extern void FUN_00000a00();
extern void FUN_0019f628();
extern void FUN_0019f728();

/* Deleting destructor: releases the owned objects, erases the element list range and frees the object when delete_flag > 0. */
PoseHolder * FUN_0019f59c(PoseHolder *self,short delete_flag)
{
  DListHead *list;
  u8 iter [4];
  u32 first;
  DListLinks *end;
  
  if (self != 0) {
    FUN_0019f628();
    list = &self->list;
    if (((list != 0) && (list != 0)) && (list != 0)) {
      end = &self->list.sentinel;
      first = (u32)self->list.sentinel.next;
      FUN_0019f728(iter,list,&first,&end);
    }
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
