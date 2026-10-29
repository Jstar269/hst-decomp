/* HSTMATCH module=hstp_trans_main.prx start=0x0028ab40 end=0x0028abcc symbol=FUN_0028ab40 lang=c99 */
/* Clone of src/eboot/FUN_0027985c.c (hstclone.py tag u4r3s): addresses substituted; exact match verified; names and types await human review. */
#include "hst/types.h"
#include "hst/pad_buttons.h"
#include "hst/mode_menu.h"

extern u32 DAT_003751d4;
extern void FUN_0001dc34();
extern void FUN_0001de88();

/* Clears the confirm/cancel button state and the menu's flag bytes. */
void FUN_0028ab40(ModeMenu *self)
{
  FUN_0001dc34(DAT_003751d4,PAD_CIRCLE);
  FUN_0001de88(DAT_003751d4,PAD_CIRCLE,1);
  FUN_0001dc34(DAT_003751d4,PAD_CROSS);
  FUN_0001de88(DAT_003751d4,PAD_CROSS,1);
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
