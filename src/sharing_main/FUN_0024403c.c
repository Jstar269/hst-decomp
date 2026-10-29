/* HSTMATCH module=hstp_trans_main.prx start=0x0024403c end=0x002440c4 symbol=FUN_0024403c lang=c99 */
/* Clone of src/eboot/FUN_00233f3c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/challenge_lobby.h"
#include "hst/vtable_obj.h"

extern u8 DAT_003b2b28;
extern ChallengeLobby * DAT_003f3994;
extern VtableObj * DAT_003f3998;
extern void FUN_00000a00();
extern u32 * FUN_0001ed28();
extern ChallengeLobby * FUN_00242d58();

/* Destructor of the object that owns the lobby: destroys the lobby, then the base; frees the object when delete_flag > 0. */
VtableObj * FUN_0024403c(VtableObj *self,short delete_flag)
{
  if (self != 0) {
    self->vtable = &DAT_003b2b28;
    DAT_003f3998 = 0;
    if (DAT_003f3994 != 0) {
      FUN_00242d58(DAT_003f3994,1);
      DAT_003f3994 = 0;
    }
    FUN_0001ed28(self,0);
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
