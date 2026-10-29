/* HSTMATCH module=hstp_trans_main.prx start=0x0015ad6c end=0x0015ae44 symbol=FUN_0015ad6c lang=c++ */
/* Clone of src/eboot/FUN_0014ed64.cpp (hstclone.py tag c39): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern "C" {
extern u8 DAT_003b1614;
extern u8 DAT_003b1698;
extern void FUN_00000a00(...);
extern void FUN_0015b32c(...);
}
struct VC_0 { virtual ~VC_0(); };

/* Container node: owns one sub-object and keeps a range record starting at +0x1c. */
struct ScriptContainer {
  u32 vtable;       /* 0x00 */
  char pad04[8];
  VC_0 *owned;      /* 0x0c deleted by the destructor */
  char pad10[0xc];
  u32 range[3];     /* 0x1c */
};

/* Deleting destructor: frees the owned object and the range record, resets the vtable, frees self when delete_flag > 0. */
extern "C" ScriptContainer * FUN_0015ad6c(ScriptContainer *self,short delete_flag)
{
  VC_0 *owned;
  u32 *range;
  u8 range_out [4];
  u32 range_end;
  u32 *range_cursor;
  
  if (self != (ScriptContainer *)0x0) {
    self->vtable = (unsigned int)(&DAT_003b1614);
    if ((char *)self + 0x4 != (char *)0) {
      owned = self->owned;
      if (owned != (VC_0 *)0x0) {
        delete owned;
        self->owned = 0;
      }
      range = self->range;
      if (((range != (u32 *)0x0) && (range != (u32 *)0x0)) &&
         (range != (u32 *)0x0)) {
        range_cursor = &self->range[1];
        range_end = self->range[2];
        FUN_0015b32c(range_out,range,&range_end,&range_cursor);
      }
    }
    if (self != (ScriptContainer *)0x0) {
      self->vtable = (unsigned int)(&DAT_003b1698);
    }
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
