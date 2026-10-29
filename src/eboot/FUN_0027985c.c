/* HSTMATCH module=EBOOT.BIN start=0x0027985c end=0x002798e8 symbol=FUN_0027985c lang=c99 */
/* Ghidra pseudocode (hstgen.py tag s256a) corrected by hand: readability pass (names, structs, constants); exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/pad_buttons.h"
#include "hst/mode_menu.h"

extern u32 DAT_002cfc8c;
extern void FUN_0001dfe8();
extern void FUN_0001e23c();

/* Clears the confirm/cancel button state and the menu's flag bytes. */
void FUN_0027985c(ModeMenu *self)
{
  FUN_0001dfe8(DAT_002cfc8c,PAD_CIRCLE);
  FUN_0001e23c(DAT_002cfc8c,PAD_CIRCLE,1);
  FUN_0001dfe8(DAT_002cfc8c,PAD_CROSS);
  FUN_0001e23c(DAT_002cfc8c,PAD_CROSS,1);
  self->unk170[0] = 0;
  self->unk170[1] = 0;
  self->unk170[2] = 0;
  self->unk170[3] = 0;
  self->unk170[4] = 0;
  self->unk170[5] = 0;
  self->unk170[6] = 0;
  self->unk170[7] = 0;
  self->unk17d = 0;
}
