/* HSTMATCH module=EBOOT.BIN start=0x00233f3c end=0x00233fc4 symbol=FUN_00233f3c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/challenge_lobby.h"
#include "hst/vtable_obj.h"

extern u8 DAT_0030985c;
extern ChallengeLobby * DAT_0034a664;
extern VtableObj * DAT_0034a668;
extern void FUN_00000a00();
extern u32 * FUN_0001f0f0();
extern ChallengeLobby * FUN_00232c58();

/* Destructor of the object that owns the lobby: destroys the lobby, then the base; frees the object when delete_flag > 0. */
VtableObj * FUN_00233f3c(VtableObj *self,short delete_flag)
{
  if (self != 0) {
    self->vtable = &DAT_0030985c;
    DAT_0034a668 = 0;
    if (DAT_0034a664 != 0) {
      FUN_00232c58(DAT_0034a664,1);
      DAT_0034a664 = 0;
    }
    FUN_0001f0f0(self,0);
    if (0 < delete_flag) {
      FUN_00000a00(self);
    }
  }
  return self;
}
