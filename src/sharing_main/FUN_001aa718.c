/* HSTMATCH module=hstp_trans_main.prx start=0x001aa718 end=0x001aa7b4 symbol=FUN_001aa718 lang=c99 */
/* Clone of src/eboot/FUN_0019d270.c (hstclone.py tag x23): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_003b0a68;
extern u8 DAT_003b122c;
extern u8 DAT_003b24b4;
extern void FUN_00000a00();
extern u32 * FUN_0010642c();
extern int * FUN_0010d2d4();

/* Object with a member at +0x120 destroyed before the base part. */
typedef struct MemberOwner {
  const void *vtable; /* 0x00 */
  char pad04[0x11c];
  u32 member[1];      /* 0x120 embedded member, torn down by the destructor */
} MemberOwner;

/* Deleting destructor: step the vtable down the class chain, destroy the member and the base part, free self when flags > 0. */
MemberOwner * FUN_001aa718(MemberOwner *self,short flags)
{
  u32 *member;

  if (self != (MemberOwner *)0x0) {
    self->vtable = &DAT_003b24b4;
    if (self != (MemberOwner *)0x0) {
      member = self->member;
      self->vtable = &DAT_003b122c;
      if ((member != (u32 *)0x0) && (member != (u32 *)0x0)) {
        FUN_0010d2d4(member,0);
      }
      if (self != (MemberOwner *)0x0) {
        self->vtable = &DAT_003b0a68;
        FUN_0010642c(self,0);
      }
    }
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
