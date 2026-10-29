/* HSTMATCH module=EBOOT.BIN start=0x0019d270 end=0x0019d30c symbol=FUN_0019d270 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"

extern u8 DAT_0030779c;
extern u8 DAT_00307f60;
extern u8 DAT_003091e8;
extern void FUN_00000a00();
extern u32 * FUN_00100b24();
extern int * FUN_00107514();

/* Object with a member at +0x120 destroyed before the base part. */
typedef struct MemberOwner {
  const void *vtable; /* 0x00 */
  char pad04[0x11c];
  u32 member[1];      /* 0x120 embedded member, torn down by the destructor */
} MemberOwner;

/* Deleting destructor: step the vtable down the class chain, destroy the member and the base part, free self when flags > 0. */
MemberOwner * FUN_0019d270(MemberOwner *self,short flags)
{
  u32 *member;

  if (self != (MemberOwner *)0x0) {
    self->vtable = &DAT_003091e8;
    if (self != (MemberOwner *)0x0) {
      member = self->member;
      self->vtable = &DAT_00307f60;
      if ((member != (u32 *)0x0) && (member != (u32 *)0x0)) {
        FUN_00107514(member,0);
      }
      if (self != (MemberOwner *)0x0) {
        self->vtable = &DAT_0030779c;
        FUN_00100b24(self,0);
      }
    }
    if (0 < flags) {
      FUN_00000a00(self);
    }
  }
  return self;
}
