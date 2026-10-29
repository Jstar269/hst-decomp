/* HSTMATCH module=EBOOT.BIN start=0x002798e8 end=0x002799a8 symbol=FUN_002798e8 lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/pad_buttons.h"
#include "hst/mode_menu.h"

extern u32 DAT_002cfc8c;
extern void FUN_0001dfe8();
extern void FUN_0001e23c();

/* Clears the confirm/cancel and left/right button state and some flag bytes. */
void FUN_002798e8(ModeMenu *self)
{
  FUN_0001dfe8(DAT_002cfc8c,PAD_CIRCLE);
  FUN_0001e23c(DAT_002cfc8c,PAD_CIRCLE,1);
  FUN_0001dfe8(DAT_002cfc8c,PAD_CROSS);
  FUN_0001e23c(DAT_002cfc8c,PAD_CROSS,1);
  self->unk170[6] = 0;
  self->unk170[7] = 0;
  FUN_0001dfe8(DAT_002cfc8c,PAD_RIGHT);
  FUN_0001e23c(DAT_002cfc8c,PAD_RIGHT,1);
  FUN_0001dfe8(DAT_002cfc8c,PAD_LEFT);
  FUN_0001e23c(DAT_002cfc8c,PAD_LEFT,1);
  self->unk17a = 0;
  self->unk17b = 0;
}
